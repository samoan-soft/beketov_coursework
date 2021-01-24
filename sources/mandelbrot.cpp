#include "mandelbrot.h"

//конструктор (long double, long double)
Complex::Complex(long double r, long double i)
    : r(r), i(i) {}

//конструктор копирования
Complex::Complex(const Complex& z)
    :r(z.r), i(z.i) {}

//перегрузка оператора = 
Complex& Complex::operator=(const Complex& z)
{
    r = z.r;
    i = z.i;
    return *this;
}

//перегрузка оператора += 
Complex& Complex::operator+=(const Complex& z)
{
    r += z.r;
    i += z.i;
    return *this;
}

//метод для взятия квадрата от модуля комплексонго числа
long double Complex::squared_module()
{
    return r * r + i * i;
}

//функция расскраски множества на границе, в зависимости от константы exactness
void coloring(sf::VertexArray& mandelbrot, int counter, int exactness, int i, int j, const int window_w, const int window_h)
{
    if (counter < exactness / 4)
    {
        mandelbrot[i * window_w + j].position = sf::Vector2f(j, i);
        sf::Color color(counter * 215 / (exactness / 4), 0, 0);
        mandelbrot[i * window_w + j].color = color;
    }
    else if (counter < exactness / 2)
    {
        mandelbrot[i * window_w + j].position = sf::Vector2f(j, i);
        sf::Color color(255, counter * 215 / (exactness / 2), 255);
        mandelbrot[i * window_w + j].color = color;
    }
    else if (counter < exactness)
    {
        mandelbrot[i * window_w + j].position = sf::Vector2f(j, i);
        sf::Color color(0, 0, counter * 215 / exactness);
        mandelbrot[i * window_w + j].color = color;
    }
}

//функция построения множества
void draw_mandelbrot(sf::VertexArray& mandelbrot, int change_x, int change_y, int exactness, float zoom, const int window_w, const int window_h)
{
    for (int i = 0; i < window_h; i++)
    {
        for (int j = 0; j < window_w; j++)
        {
            //зум в корординаты change_x и change_y
            long double x = (static_cast<long double>(j) - change_x) / zoom;
            long double y = (static_cast<long double>(i) - change_y) / zoom;
            Complex buf(x,y);
            Complex z1(buf);
            int counter{0};
            for (int k = 0; k < exactness; k++)
            {
                //применяем преобразование вида z->z+Const по орбите buf(x, y)
                Complex z2(z1.r * z1.r - z1.i * z1.i, 2 * z1.r * z1.i);
                z2 += buf;
                z1 = z2;
                counter++;

                //неравенство (Xn)^2+(Yn)^2 > 3 для проверки 
                if (z1.squared_module() > 3.0) break;
            }
            coloring(mandelbrot, counter, exactness, i, j, window_w, window_h);
        }
    }
}