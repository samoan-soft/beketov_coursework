/*!
\defgroup Sierpinski треугольник Серпинского
\brief Данный модуль описывает построение самоподобного треугольника Серпинского.

На данный момент он поддерживает следующие функции:
Построение самого фрактала по заданным размерам;
Изменение порядка итерации по нажатии ЛКМ и ПКМ, на
+ 1 и - 1 соответственно; максимальное количество итераций - 10,
минимальное - 1.
*/

/*!
\ingroup Sierpinski
\file
\brief Заголовочный файл с определением функций draw и sierpinski_triangle

Данный файл содержит в себе определение функций draw и sierpinski_triangle, 
отвечающих за создание спрайта фрактала и его отрисоки.
*/
#ifndef _SIERPINSKI_H_
#define _SIERPINSKI_H_

#include <SFML/Graphics.hpp>

/*!
\ingroup Sierpinski
Рекурсивная функция, создающая спрайт фрактаьного треугольника - sf::ConvexShape и отрисовывает его в объекте
sf::RenderWindow, переданном по ссылке.
\param top координаты точки треугольника, объект класса sf::Vector2f
\param left координаты точки треугольника, объект класса sf::Vector2f
\param right координаты точки треугольника, объект класса sf::Vector2f
\param current_iteration текущая итерация
\param window окно программы, объект класса sf::RenderWindow
\param user_iteration порядок итерации, заданный пользователем
\param user_limit_sprite спрайт окна приложения - заданный по размерам window_w, window_h, является ограничением в простроении треугольника
\param user_color цвет заданный пользователем, объект класса sf::Color 
\return в данной функции return нужен для выхода из рекурсии, по достижении построения нужной итерации
*/
void sierpinski_triangle(const sf::Vector2f& top, const sf::Vector2f& left, const sf::Vector2f& right, int current_iteration, sf::RenderWindow& window, int user_iteration, sf::RectangleShape& user_limit_sprite, const sf::Color& user_color);

/*!
\ingroup Sierpinski
Функция, итеративно вычисляющая значение точек треугольников и вызывающая функцию sierpinski_triangle.
\param window окно программы, объект класса sf::RenderWindow
\param user_limit_sprite спрайт окна приложения - заданный по размерам window_w, window_h, является ограничением в простроении треугольника
\param top координаты точки треугольника, объект класса sf::Vector2f
\param left координаты точки треугольника, объект класса sf::Vector2f
\param right координаты точки треугольника, объект класса sf::Vector2f
\param user_iteration порядок итерации, заданный пользователем
\param user_color цвет заданный пользователем, объект класса sf::Color
\return в данной функции return отсутствует, так как она передает управление sierpinski_triangle
*/
void draw(sf::RenderWindow& window, sf::RectangleShape& user_limit_sprite, sf::Vector2f& top, sf::Vector2f& left, sf::Vector2f& right, int user_iteration, const sf::Color& user_color);

#endif // _SIERPINSKI_H_