#include <SFML/Graphics.hpp>
#include "playerCharacter.hpp"
#include "surface.hpp"
#include "layer.hpp"
#include <iostream>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    
    Surface surface;
	surface.loadTexture("../res/images/map.jpg");
	Layer layer1;
	layer1.setSurface(surface);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
