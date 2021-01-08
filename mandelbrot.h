#ifndef _MANDELBROT_H_
#define _MANDELBROT_H_

#include <SFML/Graphics.hpp>
#include <complex>


void set_color(int& red, int& green, int& blue);//coloring pages on the border
void draw_Mandelbrot(sf::Vector2<long double> x, sf::Vector2<long double> y);

#endif 
