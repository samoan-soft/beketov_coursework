#include "mandelbrot.h"
#include <cstdio>
int main()
{
	sf::RenderWindow window(sf::VideoMode(1440, 960), "");

	sf::Sprite f_sprite;
	sf::Texture f_texture;
	f_texture.loadFromFile("background.jpg");
	f_sprite.setTexture(f_texture);

	sf::Sprite exit_sprite;
	sf::Texture exit_texture;
	exit_texture.loadFromFile("exit.png");
	exit_sprite.setTexture(exit_texture);
	exit_sprite.setPosition(60, 750);

	sf::Sprite mandelbrot_sprite;
	sf::Texture mandelbrot_texture;
	mandelbrot_texture.loadFromFile("mandelbrot.png");
	mandelbrot_sprite.setTexture(mandelbrot_texture);
	mandelbrot_sprite.setPosition(60, 550);

	sf::Sprite s_mandelbrot;
	sf::Texture t_mandelbrot;

	bool menu = true;
	bool mandelbrot_flag = false;

	while (window.isOpen())
	{
		sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();

			if (mandelbrot_flag==false)
			{
				window.clear();
				window.draw(f_sprite);
				window.draw(exit_sprite);
				window.draw(mandelbrot_sprite);
				window.display();
			}

			if (mandelbrot_flag) 
			{
				window.clear();
				window.draw(s_mandelbrot);
				window.display();
			}

			if (event.type == sf::Event::MouseMoved && menu)
			{
				exit_sprite.setColor(sf::Color::White);
				mandelbrot_sprite.setColor(sf::Color::White);
				if ((mouse_position.x >= 58) && (mouse_position.x <= 430) && (mouse_position.y >= 746) && (mouse_position.y <= 848))
				{
					exit_sprite.setColor(sf::Color::Magenta);
				}
				if ((mouse_position.x >= 58) && (mouse_position.x <= 430) && (mouse_position.y >= 546) && (mouse_position.y <= 648))
				{
					mandelbrot_sprite.setColor(sf::Color::Magenta);
				}
			}
			if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left && (mandelbrot_flag==false))
			{
				if((mouse_position.x >= 58) && (mouse_position.x <= 430) && (mouse_position.y >= 746) && (mouse_position.y <= 848)) window.close();
				if ((mouse_position.x >= 58) && (mouse_position.x <= 430) && (mouse_position.y >= 546) && (mouse_position.y <= 648) && (mandelbrot_flag == false))
				{
					mandelbrot_flag = true;
					draw_Mandelbrot(sf::Vector2<long double>(-2.5, 4), sf::Vector2<long double>(-1, 2));
					t_mandelbrot.loadFromFile("mandelbrot_image.png");
					s_mandelbrot.setTexture(t_mandelbrot);
					std::remove("mandelbrot_image.png");
				}
			}
		}

	}
	return 0;
}