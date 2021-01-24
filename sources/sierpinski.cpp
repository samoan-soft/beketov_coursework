#include "sierpinski.h"

void sierpinski_triangle(const sf::Vector2f& top, const sf::Vector2f& left, const sf::Vector2f& right, int current_iteration, sf::RenderWindow& window, int user_iteration, sf::RectangleShape& user_limit_sprite, const sf::Color& user_color);

void draw(sf::RenderWindow& window, sf::RectangleShape& user_limit_sprite, sf::Vector2f& top, sf::Vector2f& left, sf::Vector2f& right, int user_iteration, const sf::Color& user_color)
{
    sf::Vector2f bottom_r_point = sf::Vector2f(user_limit_sprite.getPosition().x + user_limit_sprite.getSize().x, 
    user_limit_sprite.getPosition().y + user_limit_sprite.getSize().y);
    sf::Vector2f top_l_point = sf::Vector2f(user_limit_sprite.getPosition());

    top = sf::Vector2f(bottom_r_point.x / 2.0 + top_l_point.x / 2.0, top_l_point.y);
    left = sf::Vector2f(top_l_point.x, bottom_r_point.y);
    right = sf::Vector2f(bottom_r_point.x, bottom_r_point.y);

    sierpinski_triangle(top, left, right, -1, window, user_iteration, user_limit_sprite, user_color);
}


void sierpinski_triangle(const sf::Vector2f& top, const sf::Vector2f& left, const sf::Vector2f& right, int current_iteration, sf::RenderWindow& window, int user_iteration, sf::RectangleShape& user_limit_sprite, const sf::Color& user_color)
{
    // на 0 итерации отрисовывается полностью закрашенный треугольник
    if (user_iteration == 0)
    {
        sf::ConvexShape shape;
        shape.setPointCount(3);
        shape.setPoint(0, top);
        shape.setPoint(1, left);
        shape.setPoint(2, right);
        shape.setFillColor(user_color);
        window.draw(shape);
        return;
    }
    
    //выход по достижению заданной итерации
    else if (current_iteration == user_iteration - 1) return;
    else
    {
        sf::Vector2f midLeft = sf::Vector2f(left.x / 2.0 + top.x / 2.0, left.y / 2.0 + top.y / 2.0);
        sf::Vector2f midRight = sf::Vector2f(right.x / 2.0 + top.x / 2.0, right.y / 2.0 + top.y / 2.0);
        sf::Vector2f midBottom = sf::Vector2f(left.x / 2.0 + right.x / 2.0, left.y / 2.0 + right.y / 2.0);

        if (current_iteration == user_iteration - 2)
        {
            sf::ConvexShape shape;
            shape.setPointCount(3);
            shape.setPoint(0, top);
            shape.setPoint(1, left);
            shape.setPoint(2, right);
            shape.setFillColor(user_color);
            window.draw(shape);
            return;
        }
        else
        {
            //рекуррентный вызов для отрисоывки внутренних треугольников
            sierpinski_triangle(top, midLeft, midRight, current_iteration + 1, window, user_iteration, user_limit_sprite, user_color);
            sierpinski_triangle(midLeft, left, midBottom, current_iteration + 1, window, user_iteration, user_limit_sprite, user_color);
            sierpinski_triangle(midRight, midBottom, right, current_iteration + 1, window, user_iteration, user_limit_sprite, user_color);
            sierpinski_triangle(midRight, midBottom, right, current_iteration + 1, window, user_iteration, user_limit_sprite, user_color);
        }
    }
}