#include "plotting.h"

#include <fstream>
#include <iostream>

void Image::write() {
  fstream file(filename+".gnu", ios::out | ios::trunc);

  int cur = 0;
  
    file << endl
	 << "set palette grey" << endl
	 << "set pm3d map" << endl
	 << "splot '-' matrix" << endl;

    file << "\t";
    for(auto v:data) {
      file << v;
      if(cur + 1 >= width) {
	cur = 0;
	file << endl << "\t";
      } else {
	file << " ";
	cur ++;
      }
    }
    file << "e" << endl;
}


int Image::plot_function(double (*func)(double x, double y), double x_min, double x_max, double y_min, double y_max) {
  for(int i1=0; i1<height; ++ i1) {
    for(int i2=0; i2<width; ++ i2) {
      double y = y_min + (1.0*i1)/(height-1) * (y_max-y_min);
      double x = x_min + (1.0*i2)/(width-1) * (x_max-x_min);
      double z = func(x, y);

      (*this)(i1, i2) = z;
    }
  }
  
  return 0;
}



void Graph::write() {
  fstream file(filename+".gnu", ios::out | ios::trunc);

  for(auto line:lines) {
    file << "plot '-'"
	 << " with lines"
	 << " title '" << line.label << "'"
	 << " lt rgb '" << line.color << "'"
	 << " using 1:2"
	 << endl;

  for(int i1=0; i1 < std::max(line.xs.size(), line.ys.size()); ++ i1 ){
    file << "\t" << line.xs[i1] << " " << line.ys[i1] << endl;
  }
  file << "\te" << endl;
  }
}  



void Graph::plot_function(const string& label, double (*func)(double x), double x_min, double x_max, int count, string color) {
  vector<double> xs, ys;

  for(int i1=0; i1<count; ++ i1) {
    double x = x_min + (1.0*i1)/(count-1) * (x_max-x_min);
    double y = func(x);
    // cout << x << ", " << y << endl;

    xs.push_back(x);
    ys.push_back(y);
  }
  add_lines(label, xs, ys, color);
}
