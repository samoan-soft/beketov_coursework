#include "mandelbrot.h"

void set_color(int& red, int& green, int& blue)//coloring pages on the border
{
	red = (red + 5) < 155 ? red + 5 : 155;
	if (red == 155)
		green = (green + 3.5) < 155 ? green + 3.5 : 155;
	if (green == 155)
		blue = (blue + 2.2) < 155 ? blue + 2.2 : 155;
}

void draw_Mandelbrot(sf::Vector2<long double> x, sf::Vector2<long double> y)
{
	const long double k = 0.0027;//expansion
	const long double l = 0.0016;//coefficients
	sf::RenderWindow window(sf::VideoMode(1440, 960), "Draw_Mandelbrot");// window 1440x960

	sf::Color color;
	sf::Image image;
	int image_x, image_y;
	image_x = image_y = 0;
	image.create(1440, 960); //texture resolution

	for (long double actual_x = x.x; actual_x <= x.y; actual_x += k, image_x++)
	{
		image_y = 0;
		while (image_x >= 1440) image_x--;

		for (long double actual_y = y.x; actual_y <= y.y; actual_y += k, image_y++)
		{
			while (image_y >= 960) image_y--;
			color = sf::Color::Black;
			std::complex<long double> z;
			int red = 0, green = 0, blue = 0;

			image.setPixel(image_x, image_y, sf::Color::Black);

			for (int i = 0; i < 300; ++i) // detail
			{
				if (std::abs(z) * std::abs(z) > 3) // x^2+y^2 = R^2
				{
					color = sf::Color(red, green, blue);
					image.setPixel(image_x, image_y, color);
					break;
				}
				z = z * z + std::complex<long double>(actual_x, actual_y);//Z_n+1 = (Z_n)^2 + Z_0;
				set_color(red, green, blue);
			}
		}
	}
	image.saveToFile("mandelbrot_image.png");
}