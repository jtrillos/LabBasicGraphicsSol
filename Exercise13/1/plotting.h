#ifndef __SIMPLEGRAPH_H
#define __SIMPLEGRAPH_H

#include <vector>
#include <string>

#include <assert.h>

using namespace std;

class Image {
  string filename;
  vector<double> data;
  int width, height;
  
 public:
 Image(const string& filename_, int width_ = 0, int height_ = 0) : filename(filename_) {
    resize(width_, height_);
  }
  
  ~Image() {
    write();
  }

  void resize(int width_, int height_) {
    this->width = width_;
    this->height = height_;
    data.resize(width*height);
  }

  void set_data(const vector<double>& data_) {
    assert(data.size() == data_.size());
    std::copy(data_.begin(), data_.end(), data.begin());
  }

  int plot_function(double (*func)(double x, double y), double x_min, double x_max, double y_min, double y_max);  
  void write();

  double operator()(int x, int y) const {
    assert(0<=x);
    assert(x<width);
    assert(0<=y);
    assert(y<height);
    return data[x+y*width];
  }
  double& operator()(int x, int y) {
    assert(0<=x);
    assert(x<width);
    assert(0<=y);
    assert(y<height);
    return data[x+y*width];
  }
};

class Graph {
  string filename;

  struct Line {
    string label, color;
    vector<double> xs, ys;
  };
  struct Arrow {
    double x;
  };

  vector<Line> lines;
  vector<Arrow> arrows;
  
 public:
 Graph(const string& filename_) : filename(filename_) {
  }
  ~Graph() {
    write();
  }

  void add_points(const string& label, const vector<double>& xs, const vector<double>& ys, const string& color) {
    Line line;
    line.label = label;
    line.xs = xs;
    line.ys = ys;
    line.color  = color;
    lines.push_back(line);
  }
  void add_lines(const string& label, const vector<double>& xs, const vector<double>& ys, const string& color) {
    Line line;
    line.label = label;
    line.xs = xs;
    line.ys = ys;
    line.color  = color;
    lines.push_back(line);
  }
  void mark_position(float x) {
    Arrow arrow;
    arrow.x = x;
    arrows.push_back(arrow);
  }


  void plot_function(const string& label, double (*func)(double x), double x_min, double x_max, int count, string color);
  
  void write();
};

#endif
