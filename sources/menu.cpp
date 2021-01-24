#include "menu.h"
#include "mandelbrot.h"
#include "tree.h"
#include "sierpinski.h"

void run_program()
{
	//�������� ���� �� ���������� window_w � window_h
	const int window_w{ 1440 }; const int window_h{ 960 };

	//��� ����������� ������� � ����� Fullscreen
	sf::RenderWindow window(sf::VideoMode(window_w, window_h), "Fractals", sf::Style::Titlebar | sf::Style::Close);

	//�������� �������� � �������� ������� ��� ���� ����
	sf::Sprite background_sprite;
	sf::Texture background_texture;
	background_texture.loadFromFile("textures/background.jpg");
	background_sprite.setTexture(background_texture);

	//�������� �������� � �������� ������� ��� ������ ������
	sf::Sprite exit_button_sprite;
	sf::Texture exit_button_texture;
	exit_button_texture.loadFromFile("textures/exit.png");
	exit_button_sprite.setTexture(exit_button_texture);
	exit_button_sprite.setPosition(60, 750);

	//�������� �������� � �������� ������� ��� ������ mandelbrot
	sf::Sprite mandelbrot_button_sprite;
	sf::Texture mandelbrot_button_texture;
	mandelbrot_button_texture.loadFromFile("textures/mandelbrot.png");
	mandelbrot_button_sprite.setTexture(mandelbrot_button_texture);
	mandelbrot_button_sprite.setPosition(60, 550);

	//�������� �������� � �������� ������� ��� ������ tree
	sf::Sprite tree_button_sprite;
	sf::Texture tree_button_texture;
	tree_button_texture.loadFromFile("textures/tree.png");
	tree_button_sprite.setTexture(tree_button_texture);
	tree_button_sprite.setPosition(60, 350);

	//�������� �������� � �������� ������� ��� ������ sierpinski
	sf::Sprite sierpinski_button_sprite;
	sf::Texture sierpinski_button_texture;
	sierpinski_button_texture.loadFromFile("textures/sierpinski.png");
	sierpinski_button_sprite.setTexture(sierpinski_button_texture);
	sierpinski_button_sprite.setPosition(60, 150);

	//��������� � ������������ ���������� ��� ������� draw_mandelbrot 
	sf::VertexArray mandelbrot(sf::Points, window_w * window_h);
	float zoom {300.0f};
	int exactness{ 200 };
	int change_x = window_w / 2; int change_y = window_h / 2;

	//������������ ���������� ��� ������� draw_tree 
	float angle{10.0};
	float turn_ch{ -90.0 };
	float multiplier{ 0.65f };

	//��������� � ������������ ���������� ��� ������� sierpinski_triangle
	sf::RectangleShape user_limit_sprite;
	int user_iteration{ 1 };
	sf::Color user_color;
	user_color = sf::Color::Magenta;

	sf::Vector2f top; sf::Vector2f left; sf::Vector2f right;

	user_limit_sprite = sf::RectangleShape();
	user_limit_sprite.setPosition(sf::Vector2f(0, 0));
	user_limit_sprite.setSize(sf::Vector2f(window_w, window_h));

	//������������� ������ ��� ��������� ��-��� ���������
	bool menu_flag{ true };
	bool mandelbrot_flag{ false };
	bool tree_flag{ false };
	bool sierpinski_flag{ false };

	
	while (window.isOpen())
	{
		//���������� ��������� �������
		sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();

			//���������� ��������� �� ������� Tab
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
			{
				window.close();
				run_program();
			}

			//����� � ���� �� ������� Escape
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
			{
				menu_flag = true;
				mandelbrot_flag = false;
				tree_flag = false;
				sierpinski_flag = false;
			}

			//��������� ������������
			if (mandelbrot_flag)
			{

				//zoom + �� ������� ���
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					change_x -= mouse_position.x - change_x; change_y -= mouse_position.y - change_y;
					zoom *= 2;
					exactness += 200;
					for (int i = 0; i < window_w * window_h; i++)
					{
						mandelbrot[i].color = sf::Color::Black;
					}
					draw_mandelbrot(mandelbrot, change_x, change_y, exactness, zoom, window_w, window_h);
				}

				//zoom - �� ������� ���
				if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && exactness > 200)
				{
					change_x += mouse_position.x - change_x; change_y += mouse_position.y - change_y;
					zoom /= 2;
					exactness -= 200;
					for (int i = 0; i < window_w * window_h; i++)
					{
						mandelbrot[i].color = sf::Color::Black;
					}
					draw_mandelbrot(mandelbrot, change_x, change_y, exactness, zoom, window_w, window_h);
				}
				window.clear();
				window.draw(mandelbrot);
				window.display();
			}

			//��������� ������
			if (tree_flag)
			{
				//��������� ���� ������� �������� �� +3 ������� �� ������� ���
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) angle += 3.0;

				//��������� ���� ������� �������� �� +3 ������� �� ������� ���
				if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && angle > 10) angle -= 3.0;
				window.clear();
				draw_tree(static_cast<float>(window_w /2.0), static_cast<float>(window_h), turn_ch, 450.0, window, angle, multiplier);
				window.display();
			}

			//��������� ������������ �����������
			if (sierpinski_flag)
			{
				//���������� �������� �� 1 �� ������� ���
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && user_iteration < 10) user_iteration++;

				//���������� �������� �� 1 �� ������� ���
				if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && user_iteration > 1) user_iteration--;
				window.clear();
				draw(window, user_limit_sprite, top, left, right, user_iteration, user_color);
				window.display();
			}

			//��������� ��-��� ����
			if (menu_flag)
			{
				window.clear();
				window.draw(background_sprite);
				window.draw(exit_button_sprite);
				window.draw(mandelbrot_button_sprite);
				window.draw(tree_button_sprite);
				window.draw(sierpinski_button_sprite);
				window.display();
			}

			//��������� ������ �� �������� �� ��� �������
			if (event.type == sf::Event::MouseMoved && menu_flag)
			{
				exit_button_sprite.setColor(sf::Color::White);
				mandelbrot_button_sprite.setColor(sf::Color::White);
				tree_button_sprite.setColor(sf::Color::White);
				sierpinski_button_sprite.setColor(sf::Color::White);

				if ((mouse_position.x >= 58) && (mouse_position.x <= 430) && (mouse_position.y >= 746) && (mouse_position.y <= 848))
				{
					exit_button_sprite.setColor(user_color);
				}
				if ((mouse_position.x >= 58) && (mouse_position.x <= 430) && (mouse_position.y >= 546) && (mouse_position.y <= 648))
				{
					mandelbrot_button_sprite.setColor(user_color);
				}
				if ((mouse_position.x >= 58) && (mouse_position.x <= 430) && (mouse_position.y >= 346) && (mouse_position.y <= 448))
				{
					tree_button_sprite.setColor(user_color);
				}
				if ((mouse_position.x >= 58) && (mouse_position.x <= 430) && (mouse_position.y >= 146) && (mouse_position.y <= 248))
				{
					sierpinski_button_sprite.setColor(user_color);
				}
			}

			//��������� ������� ������� �� ������ � ��������� ����-��� ���������
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mandelbrot_flag)
			{
				if ((mouse_position.x >= 58) && (mouse_position.x <= 430) && (mouse_position.y >= 746) && (mouse_position.y <= 848)) window.close();
				if ((mouse_position.x >= 58) && (mouse_position.x <= 430) && (mouse_position.y >= 546) && (mouse_position.y <= 648) && !mandelbrot_flag)
				{
					draw_mandelbrot(mandelbrot, change_x, change_y, exactness, zoom, window_w, window_h);
					mandelbrot_flag = true;
					menu_flag = false;
				}
				if ((mouse_position.x >= 58) && (mouse_position.x <= 430) && (mouse_position.y >= 346) && (mouse_position.y <= 448) && !tree_flag)
				{
					tree_flag = true;
					menu_flag = false;
				}
				if ((mouse_position.x >= 58) && (mouse_position.x <= 430) && (mouse_position.y >= 146) && (mouse_position.y <= 248) && !sierpinski_flag)
				{
					sierpinski_flag = true;
					menu_flag = false;
				}
			}
		}

	}
}