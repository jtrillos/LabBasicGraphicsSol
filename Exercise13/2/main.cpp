#include <iostream>

#include "SimpleImage.h"
#include "tools.h"
#include "gradient_descent_with_steps.h"

/* Use the make_absolute macro to wrap all relative file paths you specify in the source code,
 * e.g. make_absolute("../resources/planet.obj").
 * This prevents that the running program cannot find files which were specified relative
 * to the position of the source code, which quickly becomes a problem with the default out
 * of source builds of most IDEs.
 *
 * The following two macros make use of the __FILE__ macro, which contains the
 * absolute path of the current source file at compile time.
 *
 * get_source_dir() strips off the file name from a path and only returns the folders
 *
 * make_absolute prepends a relative path with the folder that contains the current source file
 */
#define get_source_dir(path) std::string(path).substr(0, std::string(path).find_last_of("/\\") + 1)
#define make_absolute(path) (get_source_dir(__FILE__) + std::string(path)).c_str()

using namespace std;

int width, height;
vector<double> dat, grad;
double sigma = 0.0;

void progress( const vector<double>& data, const vector<double>& grad );
void outputImage( const vector<double>& data );
double& queryPixel( vector<double>& data, int x, int y );
double queryPixel( const vector<double>& data, int x, int y );
double energySmoothnessAnisotropic( const vector<double>& img, vector<double>& grad );

double func_h(double d,double sigma)
{
    double w = 1.0 / exp(pow(-0.1, 2) / pow(sigma, 2));
    return w * exp(pow(-d, 2) / pow(sigma, 2));
}

double deriv_h(double d, double sigma)
{
    double val = 1 - (pow(d, 2) / pow(sigma, 2));
    return 2 * d * func_h(d, sigma) * val;
}

void progress(const vector<double> & data, const vector<double> & grad)
{
    outputImage(data);
    outputImage(grad);
}

void outputImage(const vector<double>& data)
{
    SimpleImage& img = *SimpleImage::getInstance();
    img.create(width,height);
    int size = data.size();
    for(int i = 0; i < size; i++){
        int nr_row = i / width;
        int nr_column = i - (nr_row * width);
        img(nr_row, nr_column) = data.at(i);
    }
    img.show();
}

double& queryPixel(vector<double>& data, int x, int y)
{
    if(x > width){
        x = width - x;
    }
    if(y > height){
        y = height - y;
    }
    int i = (x * width) + y;
    return data.at(i);
}

double queryPixel(const vector<double>& data, int x, int y)
{
    if(x >= width){
        x = x - width;
    }
    else if(x < 0){
        x = width + x;
    }
    if(y >= height){
        y = y - height;
    }
    else if(y < 0){
        y = height + y;
    }
    int i = (x * width) + y;
    return data.at(i);
}

double energySmoothnessAnisotropic(const vector<double>& img, vector<double> & grad)
{
    double energy = 0.0;
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            double val1 = queryPixel(img, i, j);
            double val2 = queryPixel(img, i + 1, j);
            double val3 = queryPixel(img, i, j + 1);
            energy += func_h(val1 - val2, sigma) + func_h(val1 - val3, sigma);
        }
    }
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            double x1 = queryPixel(img, i, j);
            double x2 = queryPixel(img, i + 1, j);
            double x3 = queryPixel(img, i - 1, j);
            double y2 = queryPixel(img, i, j + 1);
            double y3 = queryPixel(img, i, j - 1);
            double value = deriv_h(x1 - x2, sigma) + deriv_h(x1 - x3, sigma) + deriv_h(x1 - y2, sigma) + deriv_h(x1 - y3, sigma);
            grad.at(i * width + j) = value;
        }
    }
    return energy;
}

void assignment_anisotropic() {
    // (a): load image and display
    SimpleImage& img = *SimpleImage::getInstance();
    img.load( make_absolute("lena.ppm") );
    img.show(); //close window to continue
    // access the image via img( x, y )

    width = img.width();
    height = img.height();
    cout << "Dimensions: " << width << " X "<< height << endl;

    for(int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){
            dat.push_back(img(x, y));
        }
    }
}

int main()
{
    assignment_anisotropic();
    grad.resize(width*height);
    sigma = 1;
    progress(dat, grad);
    vector<double> sol = gradient_descent_nd_with_steps(dat, energySmoothnessAnisotropic, -1, -1, progress);
    outputImage(sol);
    sigma = 0.5;
    vector<double> sol2 = gradient_descent_nd_with_steps(dat, energySmoothnessAnisotropic, -1, -1);
    outputImage(sol2);
    sigma = 0.1;
    vector<double> sol3 = gradient_descent_nd_with_steps(dat, energySmoothnessAnisotropic, -1, -1);
    outputImage(sol3);
    return 0;
}
