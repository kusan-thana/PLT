#include "sfmlclient.hpp"

/**
 * Client SFMLClass
**/
SFMLClient::SFMLClient() : window(sf::VideoMode(1024, 512), "Fantasy World!") {
}

bool SFMLClient::acquireControls(){
	
	sf::Event event;
	
	while (this->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		this->window.close();
	}
	
	return this->window.isOpen();
}
void SFMLClient::updateDisplay(){
	
	this->window.clear();
	//this->window.draw(surface);
	this->window.display();
}
