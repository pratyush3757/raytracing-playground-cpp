#ifndef RT_CANVAS
#define RT_CANVAS

#include "rt_colors.hpp"
#include <cstddef>
#include <iostream>
#include <vector>

class rt_canvas {
public:
  rt_canvas(size_t width, size_t height) : 
    width(width), height(height),
    canvas(height, std::vector<rt_color>(width, rt_color())) {}

  void write_pixel(size_t x, size_t y, rt_color color) {
    if (x >= width || y >= height) {
      std::cerr << "Out of range access (X, Y) | (Width, Height)"
        << "(" << x 
        << ", " << y 
        << ") | (" << this->width 
        << ", " << this->height 
        << ")" << std::endl;
      return;
    }

    canvas[y][x] = color;
  }

public:
  std::vector<std::vector<rt_color>> canvas;
  size_t width, height;
};

#endif // !RT_CANVAS
