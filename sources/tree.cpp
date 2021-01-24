#include "tree.h"

void draw_tree(float tree_x, float tree_y, float turn_ch, float length, sf::RenderWindow& window, float angle, float multiplier)
{
    //выход из рекурсии по достижении длины отростка < 1
    if (length < 1)
    {
        return;
    }
    else
    {
        //коэфициент для уменьшения длины отростка 
        length = multiplier * length;

        //вычисление координат конца отростка с учетом поворота
        float change_x = tree_x + length * cos(turn_ch * 3.14159265358979323846 / 180.0);
        float change_y = tree_y + length * sin(turn_ch * 3.14159265358979323846 / 180.0);

        //gстроение отростка по двум точкам
        sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(tree_x, tree_y), sf::Color::Magenta),
            sf::Vertex(sf::Vector2f(change_x, change_y), sf::Color::Magenta)
        };

        //отрисовка линии
        window.draw(line, 2, sf::Lines);

        //рекуррентный вызов для построения левых отростков
        draw_tree(change_x, change_y, turn_ch - angle, length, window, angle, multiplier);

        //рекуррентный вызов для построения правых отростков
        draw_tree(change_x, change_y, turn_ch + angle, length, window, angle, multiplier);
    }

}
