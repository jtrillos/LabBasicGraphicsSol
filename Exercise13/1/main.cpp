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
vector<double> d, grad;

void progress( const vector<double>& data, const vector<double>& grad );
void outputImage( const vector<double>& data );
double& queryPixel( vector<double>& data, int x, int y );
double queryPixel( const vector<double>& data, int x, int y );
double energySmoothnessIsotropic( const vector<double>& img, vector<double>& grad );

double func_h(double val1,double val2)
{
    return pow((val1 - val2), 2);
}

double deriv_h(double val1,double val2)
{
    return 2 * (val1 - val2);
}

void progress(const vector<double> & data, const vector<double> & grad)
{
    outputImage(data);
    outputImage(grad);
}

void outputImage(const vector<double>& data)
{
    SimpleImage& img = *SimpleImage::getInstance();
    img.create(width, height);
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

double queryPixel(const vector<double>& data,int x, int y)
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


double energySmoothnessIsotropic(const vector<double>& img, vector<double> & grad)
{
    double energy = 0.0;
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            double val1 = queryPixel(img, i, j);
            double val2 = queryPixel(img, i + 1, j);
            double val3 = queryPixel(img, i, j + 1);
            energy += func_h(val1, val2) + func_h(val1, val3);
        }
    }

    //this is not working. I do not know why if i comment this part then it works but grad = 0. :s
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            double x1 = queryPixel(img, i, j);
            double x2 = queryPixel(img, i + 1, j);
            double x3 = queryPixel(img, i - 1, j);
            double y2 = queryPixel(img, i, j + 1);
            double y3 = queryPixel(img, i, j - 1);
            double value = deriv_h(x1, x2) + deriv_h(x1, x3) + deriv_h(x1, y2) + deriv_h(x1, y3);
            grad.at(i * width + j) = value;
        }
    }
    return energy;
}

void assignment_isotropic() {
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
            d.push_back(img(x, y));
        }
    }
}

int main()
{
    assignment_isotropic();
    grad.resize(width*height);
    energySmoothnessIsotropic(d, grad);
    progress(d, grad);
    vector<double> sol = gradient_descent_nd_with_steps(d, energySmoothnessIsotropic, -1, 100, progress);
    outputImage(sol);
    return 0;
}
