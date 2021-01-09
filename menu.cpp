#include "menu.h"
#include "mandelbrot.h"

void run_program()
{
	const int window_w = 1440; const int window_h = 960;
	sf::RenderWindow window(sf::VideoMode(window_w, window_h), "Fractals");

	sf::Sprite background_sprite;
	sf::Texture background_texture;
	background_texture.loadFromFile("background.jpg");
	background_sprite.setTexture(background_texture);

	sf::Sprite exit_button_sprite;
	sf::Texture exit_button_texture;
	exit_button_texture.loadFromFile("exit.png");
	exit_button_sprite.setTexture(exit_button_texture);
	exit_button_sprite.setPosition(60, 750);

	sf::Sprite mandelbrot_button_sprite;
	sf::Texture mandelbrot_button_texture;
	mandelbrot_button_texture.loadFromFile("mandelbrot.png");
	mandelbrot_button_sprite.setTexture(mandelbrot_button_texture);
	mandelbrot_button_sprite.setPosition(60, 550);

	sf::VertexArray mandelbrot(sf::Points, window_w * window_h);
	float zoom = 300.0f;
	int exactness = 200;
	int change_x = window_w / 2; int change_y = window_h / 2;

	bool menu_flag = true; bool mandelbrot_flag = false;

	while (window.isOpen())
	{
		sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
			{
				window.close();
				run_program();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
			{
				menu_flag = true;
				mandelbrot_flag = false;
			}

			if (mandelbrot_flag)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					change_x -= mouse_position.x - change_x; change_y -= mouse_position.y - change_y;
					zoom *= 2;
					exactness += 200;
					for (int i = 0; i < window_w * window_h; i++)
					{
						mandelbrot[i].color = sf::Color::Black;
					}
					draw_mandelbrot(mandelbrot, change_x, change_y, exactness, zoom);
				}
				window.clear();
				window.draw(mandelbrot);
				window.display();
			}

			if (menu_flag)
			{
				window.clear();
				window.draw(background_sprite);
				window.draw(exit_button_sprite);
				window.draw(mandelbrot_button_sprite);
				window.display();
			}

			if (event.type == sf::Event::MouseMoved && menu_flag)
			{
				exit_button_sprite.setColor(sf::Color::White);
				mandelbrot_button_sprite.setColor(sf::Color::White);
				if ((mouse_position.x >= 58) && (mouse_position.x <= 430) && (mouse_position.y >= 746) && (mouse_position.y <= 848))
				{
					exit_button_sprite.setColor(sf::Color::Magenta);
				}
				if ((mouse_position.x >= 58) && (mouse_position.x <= 430) && (mouse_position.y >= 546) && (mouse_position.y <= 648))
				{
					mandelbrot_button_sprite.setColor(sf::Color::Magenta);
				}
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mandelbrot_flag)
			{
				if ((mouse_position.x >= 58) && (mouse_position.x <= 430) && (mouse_position.y >= 746) && (mouse_position.y <= 848)) window.close();
				if ((mouse_position.x >= 58) && (mouse_position.x <= 430) && (mouse_position.y >= 546) && (mouse_position.y <= 648) && !mandelbrot_flag)
				{
					draw_mandelbrot(mandelbrot, change_x, change_y, exactness, zoom);
					mandelbrot_flag = true;
					menu_flag = false;
				}
			}
		}

	}
}