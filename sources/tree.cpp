#include "tree.h"

void draw_tree(float tree_x, float tree_y, float turn_ch, float length, sf::RenderWindow& window, float angle, float multiplier)
{
    //����� �� �������� �� ���������� ����� �������� < 1
    if (length < 1)
    {
        return;
    }
    else
    {
        //���������� ��� ���������� ����� �������� 
        length = multiplier * length;

        //���������� ��������� ����� �������� � ������ ��������
        float change_x = tree_x + length * cos(turn_ch * 3.14159265358979323846 / 180.0);
        float change_y = tree_y + length * sin(turn_ch * 3.14159265358979323846 / 180.0);

        //g�������� �������� �� ���� ������
        sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(tree_x, tree_y), sf::Color::Magenta),
            sf::Vertex(sf::Vector2f(change_x, change_y), sf::Color::Magenta)
        };

        //��������� �����
        window.draw(line, 2, sf::Lines);

        //������������ ����� ��� ���������� ����� ���������
        draw_tree(change_x, change_y, turn_ch - angle, length, window, angle, multiplier);

        //������������ ����� ��� ���������� ������ ���������
        draw_tree(change_x, change_y, turn_ch + angle, length, window, angle, multiplier);
    }

}
