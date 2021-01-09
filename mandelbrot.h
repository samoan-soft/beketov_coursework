#ifndef _MANDELBROT_H_
#define _MANDELBROT_H_

#include <SFML/Graphics.hpp>

void draw_mandelbrot(sf::VertexArray& vertexarray, int pixel_shift_x, int pixel_shift_y, int precision, float zoom);

#endif 
