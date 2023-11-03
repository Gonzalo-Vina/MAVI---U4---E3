#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace sf;

int main()
{
	//////Variables//////
	Texture textureRed, textureBlue;
	Sprite circleRed, circleBlue;
	std::vector<Sprite> circulosPantalla;

	//Cargamos la textura del archivo
	textureRed.loadFromFile("assets/rcircle.png");
	textureBlue.loadFromFile("assets/rcircleb.png");

	//Cargamos el material del sprite
	circleRed.setTexture(textureRed);
	circleBlue.setTexture(textureBlue);

	/////Creamos la ventana//////
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Que ventana horrible");

	/////Loop principal//////
	while (App.isOpen())
	{
		Event evt;
		while (App.pollEvent(evt)) {
			/////Procesar eventos//////
			switch (evt.type)
			{
				/////Si se cerro la ventana//////
			case sf::Event::Closed:
				App.close();
				break;

			case::Event::MouseButtonPressed:
				if (Mouse::isButtonPressed(Mouse::Left)) {
					circulosPantalla.push_back(circleRed);
				}
				if (Mouse::isButtonPressed(Mouse::Right)) {
					circulosPantalla.push_back(circleBlue);
				}				
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape) == true)
				App.close();
		}	

		for (int i = 0; i < circulosPantalla.size(); i++)
		{
			circulosPantalla[i].setPosition(circulosPantalla[i].getPosition().x + 0.25f, circulosPantalla[i].getPosition().y + 0.25f);
		}


		App.clear();

		for (int i = 0; i < circulosPantalla.size(); i++)
		{
			App.draw(circulosPantalla[i]);
		}

		App.display();
	}
	return 0;
}

