#ifndef SFMLClient_H
#define SFMLClient_H
#include <SFML/Graphics.hpp>
#include "client.hpp"

class SFMLClient : public Client {

	protected:
		sf::RenderWindow window;
		virtual bool acquireControls();
		//virtual void stateChanged();
		virtual void updateDisplay();
	
	public:
		SFMLClient();
};

#endif
