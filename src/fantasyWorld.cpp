#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "playerCharacter.hpp"
#include "surface.hpp"
#include "layer.hpp"
#include "scene.hpp"
#include "statictile.hpp"


using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 512), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    
    Surface surface;
	surface.loadTexture("../res/images/dungeon.gif");
	//~ Layer layer1;
	//~ layer1.setSurface(surface);
	StaticTile statictile;

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
