/*!
\defgroup Sierpinski ����������� �����������
\brief ������ ������ ��������� ���������� ������������� ������������ �����������.

�� ������ ������ �� ������������ ��������� �������:
���������� ������ �������� �� �������� ��������;
��������� ������� �������� �� ������� ��� � ���, ��
+ 1 � - 1 ��������������; ������������ ���������� �������� - 10,
����������� - 1.
*/

/*!
\ingroup Sierpinski
\file
\brief ������������ ���� � ������������ ������� draw � sierpinski_triangle

������ ���� �������� � ���� ����������� ������� draw � sierpinski_triangle, 
���������� �� �������� ������� �������� � ��� ��������.
*/
#ifndef _SIERPINSKI_H_
#define _SIERPINSKI_H_

#include <SFML/Graphics.hpp>

/*!
\ingroup Sierpinski
����������� �������, ��������� ������ ����������� ������������ - sf::ConvexShape � ������������ ��� � �������
sf::RenderWindow, ���������� �� ������.
\param top ���������� ����� ������������, ������ ������ sf::Vector2f
\param left ���������� ����� ������������, ������ ������ sf::Vector2f
\param right ���������� ����� ������������, ������ ������ sf::Vector2f
\param current_iteration ������� ��������
\param window ���� ���������, ������ ������ sf::RenderWindow
\param user_iteration ������� ��������, �������� �������������
\param user_limit_sprite ������ ���� ���������� - �������� �� �������� window_w, window_h, �������� ������������ � ����������� ������������
\param user_color ���� �������� �������������, ������ ������ sf::Color 
\return � ������ ������� return ����� ��� ������ �� ��������, �� ���������� ���������� ������ ��������
*/
void sierpinski_triangle(const sf::Vector2f& top, const sf::Vector2f& left, const sf::Vector2f& right, int current_iteration, sf::RenderWindow& window, int user_iteration, sf::RectangleShape& user_limit_sprite, const sf::Color& user_color);

/*!
\ingroup Sierpinski
�������, ���������� ����������� �������� ����� ������������� � ���������� ������� sierpinski_triangle.
\param window ���� ���������, ������ ������ sf::RenderWindow
\param user_limit_sprite ������ ���� ���������� - �������� �� �������� window_w, window_h, �������� ������������ � ����������� ������������
\param top ���������� ����� ������������, ������ ������ sf::Vector2f
\param left ���������� ����� ������������, ������ ������ sf::Vector2f
\param right ���������� ����� ������������, ������ ������ sf::Vector2f
\param user_iteration ������� ��������, �������� �������������
\param user_color ���� �������� �������������, ������ ������ sf::Color
\return � ������ ������� return �����������, ��� ��� ��� �������� ���������� sierpinski_triangle
*/
void draw(sf::RenderWindow& window, sf::RectangleShape& user_limit_sprite, sf::Vector2f& top, sf::Vector2f& left, sf::Vector2f& right, int user_iteration, const sf::Color& user_color);

#endif // _SIERPINSKI_H_