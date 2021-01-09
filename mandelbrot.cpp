#include "mandelbrot.h"

const int window_w = 1440; const int window_h = 960;

struct complex
{
    long double r{0};
    long double i{0};
};

void coloring(sf::VertexArray& mandelbrot, int counter, int exactness, int i, int j)
{
    if (counter < exactness / 4.0f)
    {
        mandelbrot[i * window_w + j].position = sf::Vector2f(j, i);
        sf::Color color(counter * 215.0f / (exactness / 4.0f), 0, 0);
        mandelbrot[i * window_w + j].color = color;
    }
    else if (counter < exactness / 2.0f)
    {
        mandelbrot[i * window_w + j].position = sf::Vector2f(j, i);
        sf::Color color(0, counter * 215.0f / (exactness / 2.0f), 0);
        mandelbrot[i * window_w + j].color = color;
    }
    else if (counter < exactness)
    {
        mandelbrot[i * window_w + j].position = sf::Vector2f(j, i);
        sf::Color color(0, 0, counter * 215.0f / exactness);
        mandelbrot[i * window_w + j].color = color;
    }
}

void draw_mandelbrot(sf::VertexArray& mandelbrot, int change_x, int change_y, int exactness, float zoom)
{
    for (int i = 0; i < window_h; i++)
    {
        for (int j = 0; j < window_w; j++)
        {
            long double x = (static_cast<long double>(j) - change_x) / zoom;
            long double y = (static_cast<long double>(i) - change_y) / zoom;
            complex buf;
            buf.r = x;
            buf.i = y;
            complex z1 = buf;
            int counter = 0;
            for (int k = 0; k < exactness; k++)
            {
                complex z2;
                z2.r = z1.r * z1.r - z1.i * z1.i; z2.i = 2 * z1.r * z1.i;
                z2.r += buf.r; z2.i += buf.i;
                z1 = z2;
                counter++;
                if (z1.r * z1.r + z1.i * z1.i > 3.0) break;
            }
            coloring(mandelbrot, counter, exactness, i, j);
        }
    }
}