/*!
\defgroup Mandelbrot множество Мандельброта
\brief Данный модуль описывает построени множества Мандельброта.

На данный момент он поддерживает следующие функции: 
Построение множества Мандельброта по заданным размерам; раскраска множества на границе; 
зумм в указанные координаты по нажатии ЛКМ; обратный зумм по нажатии ПКМ.
*/

/*!
\ingroup Mandelbrot
\file
\brief Заголовочный файл с определением функций coloring, draw_mandelbrot
и струкутры Complex

Данный файл содержит в себе определение функций coloring, draw_mandelbrot, 
отвечающих за раскраску множества Манельброта на границе и его построения соответственно;
Также содержит определение структуры Complex, некоторых ее конструкторов, перегруженных 
операторов и одного метода.
*/
#ifndef _MANDELBROT_H_
#define _MANDELBROT_H_

#include <SFML/Graphics.hpp>

/*!
\ingroup Mandelbrot
Структура, описывающая комплексное число,
имеющая один метод - взятие модуля комплексного числа и возведения его в клвадрат.
*/
struct Complex 
{
	long double r{ 0 };///Поле Re
	long double i{ 0 };///Поле Im
    ~Complex() = default;
    Complex();
    Complex(long double r, long double i);///конструктор задания по Re и Im частям
    Complex(const Complex& z);///конструктор копирования комплексного числа

    Complex& operator=(const Complex& z);///Перегурзка =
    Complex& operator+=(const Complex& z);///Перегурзка +=
    long double squared_module();///метод для выполнения операции взятия модуля и возведения в квадрат
};

/*!
\ingroup Mandelbrot
Расскрашивает множество Мандельброта на границе, 
по принципу в зависимости от стремлении к константе exactness
\param mandelbrot спрайт множества 
\param counter итерация точки
\param exactness значение для проверки на границе, путем сравнения
\param i переменная хранящая в сетебе номер пикселя по высоте
\param j переменная хранящая в сетебе номер пикселя по ширине
\param window_w ширина окна
\param window_h высота окна
\return не имеет возвращаемого значения
*/
void coloring(sf::VertexArray& mandelbrot, int counter, int exactness, int i, int j, const int window_w, const int window_h);

/*!
\ingroup Mandelbrot
Функция, создающая спрайт множества Мандельброта по начальным параметрам
\param mandelbrot спрайт множества
\param change_x параметр для зумма в указанную координату по X
\param change_y параметр для зумма в указанную координату по Y
\param exactness значение для проверки на границе, путем сравнения 
\param zoom множетель зумма
\param i переменная хранящая в сетебе номер пикселя по высоте
\param j переменная хранящая в сетебе номер пикселя по ширине
\param window_w ширина окна
\param window_h высота окна
\return не имеет возвращаемого значения
*/
void draw_mandelbrot(sf::VertexArray& mandelbrot, int change_x, int change_y, int exactness, float zoom, const int window_w, const int window_h);

#endif // _MANDELBROT_H_
