#ifndef __SIMPLEIMAGE_H
#define __SIMPLEIMAGE_H

#include <freeglut/include/GL/glut.h>
#include <string>
#include <vector>

class SimpleImage
{ 
public:
	static SimpleImage* getInstance(); //use this to get a pointer to the ImageClass

	// This function shows the image in a separate window
	// Closing the window will continue program execution
	void show();

	// creates a new, empty (i.e. black) image with the given dimensions
	void create( unsigned int w, unsigned int h );

	// load image from PPM-file
	void load( const std::string & filename );

	// tells the dimensions of the image
	unsigned int width();
	unsigned int height();

	// get access to a specific pixel
	// x in [0,1,...,width()-1] is horizontal index
	// y in [0,1,...,height()-1] is vertical index
	// index (0,0) corresponds to the top-left corner
	double & operator()( unsigned int x, unsigned int y );

// DO NOT CONSIDER ANYTHING BELOW THIS LINE AS IT IS PRIVATE!
private:
	SimpleImage();

	void displayCallback();
	void reshapeCallback(int w,int h);
	unsigned int img_width, img_height;
	std::vector<double> pixelData;
	int wnd_left, wnd_top, wnd_width, wnd_height;

	GLuint texId;

	static void display();
	static void reshape(int w,int h);
	static SimpleImage* instance;
};

#endif
