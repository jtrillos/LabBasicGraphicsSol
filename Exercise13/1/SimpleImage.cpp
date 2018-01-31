#include <freeglut/include/GL/freeglut.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "SimpleImage.h"
#include <assert.h>
#include <algorithm>

SimpleImage* SimpleImage::getInstance()
{
	if ( instance == NULL )
		instance = new SimpleImage();

	return instance;
}

void SimpleImage::show()
{
	int argi = 0;
	char* argv = new char[10];
	glutInit( &argi, &argv );
	glutSetOption( GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS );
	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowPosition( wnd_left, wnd_top );
    glutInitWindowSize( wnd_width, wnd_height );   
    glutCreateWindow( "SimpleImage Viewer -- close to continue" );
	glutReshapeWindow(width(),height());
	glutDisplayFunc( display );
	glutReshapeFunc( reshape );

	if ( width() > 0 && height() > 0 )
	{
		//upload the texture
	//	if ( texId == 0xFFFFFFFF )
		{
			glPixelStorei(GL_UNPACK_ALIGNMENT,1);
			glGenTextures(1, &texId);
			glBindTexture(GL_TEXTURE_2D,  texId);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP );
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP );
		}
		glBindTexture(GL_TEXTURE_2D,  texId);
		std::vector<float> glData;
		double minVal = *std::min_element( pixelData.begin(), pixelData.end() );
		double maxVal = *std::max_element( pixelData.begin(), pixelData.end() );
		double range = maxVal-minVal;
		for ( size_t i = 0; i < width()*height();  ++i ) {
			float d = (float)( (pixelData[i]-minVal)/( maxVal-minVal) );

			unsigned char ch = static_cast<unsigned char>(((pixelData[i]-minVal)/range * 255));
			glData.push_back( d );
 			glData.push_back( d );
 			glData.push_back( d );
 			glData.push_back( 1 );
// 			glData[i] = (0x01010100 * ch) | 0x000000FF;
		}
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width(), height(), 0, GL_RGBA, GL_FLOAT, glData.data() );
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width(), height(), 0, GL_LUMINANCE, GL_FLOAT, glData.data() );
		glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE );
	}

	glutMainLoop();
}

void SimpleImage::create( unsigned int w, unsigned int h )
{
	img_width = w;
	img_height = h;
	pixelData.resize( w*h );
	std::fill( pixelData.begin(), pixelData.end(), 0.0f );
}

void SimpleImage::load( const std::string & filename )
{
	//assume that given file is binary PPM
	std::ifstream in( filename.c_str(), std::ios::binary | std::ios::in );
	assert( in.is_open() );
	std::string line;
	std::getline( in, line );
	assert( line[0] == 'P' && line[1] == '6' ); //check for magic number
	std::getline( in, line );
	while ( line[0] == '#' ) std::getline( in, line ); //ignore comments

	int maxValueInt, w, h;

	std::istringstream parser( line );
	parser >> w >> h;
	in >> maxValueInt;

	int bytePerPixel = maxValueInt>=256?2:1;

	create( w, h );

	{
		char ch;
		in >> ch;
		if( ch != '\n' ) {
			in.putback( ch );
		}
	}


	//read the pixel values (for performance reasons: all at once)
	std::vector<unsigned char> buffer(bytePerPixel * 3 * w * h );
	in.read( (char*)buffer.data(), buffer.size() + 1 );
	in.close();



	//copy and convert the values to float
	std::vector<unsigned char>::const_iterator pVal = buffer.begin();
	for ( int i=0; i< w*h; ++i, pVal+=3*bytePerPixel ) {
		float maxValue( (float) maxValueInt );

		float r = pVal[0]/maxValue;
		float g = pVal[1]/maxValue;
		float b = pVal[2]/maxValue;

		float res = sqrt(r*r+g*g+b*b);

		pixelData[i] = res;
	}
}

unsigned int SimpleImage::width()
{
	return img_width;
}

unsigned int SimpleImage::height()
{
	return img_height;
}

double & SimpleImage::operator()( unsigned int x, unsigned int y )
{
	assert( x >= 0 && x < img_width && y >= 0 && y < img_height );
	return pixelData[y*img_width + x];
}

SimpleImage::SimpleImage()
	: wnd_left(100), wnd_top(100), wnd_width(400), wnd_height(300)
	, img_width(0), img_height(0), texId(0xFFFFFFFF)
{
}

void SimpleImage::displayCallback()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(1, 1, 1, 0.);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0,0, (int)(wnd_width),(int)(wnd_height));
	glLoadIdentity();
	glOrtho(0, 1, 1, 0, -1, 1); //choose axes to comply with usual image coords (0,0 is top-left corner)

	glEnable( GL_TEXTURE_2D );
	glBindTexture(GL_TEXTURE_2D,  texId);
	glBegin( GL_QUADS );
		glColor3f( 1, 0, 0 );
		glTexCoord2f(0,0);
		glVertex2f(0,0);

		glColor3f( 0, 1, 0 );
		glTexCoord2f(1,0);
		glVertex2f(1,0);

		glColor3f( 0, 0, 1 );
		glTexCoord2f(1,1);
		glVertex2f(1,1);

		glColor3f( 0, 1, 1 );
		glTexCoord2f(0,1);
		glVertex2f(0,1);
	glEnd();

	glDisable( GL_TEXTURE_2D );

	glutSwapBuffers();
}
void SimpleImage::reshapeCallback(int w, int h)
{
    wnd_width=w;
    wnd_height=h;
    glViewport(0,0,wnd_width,wnd_height);
}

void SimpleImage::display(){ instance->displayCallback(); }
void SimpleImage::reshape(int w,int h){ instance->reshapeCallback(w,h); }


SimpleImage* SimpleImage::instance = NULL;
