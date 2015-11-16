#ifndef SFMLClient_H
#define SFMLClient_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "client.hpp"
#include "sfmlSurface.hpp"
#include "surface.hpp"

namespace client {

class SFMLClient : public Client {

	protected:
		sf::RenderWindow window;
		std::vector<Surface*> surfaces;
		sf::Text text;
		sf::Font font;
		
		void init();
		virtual bool acquireControls();
		//virtual void stateChanged();
		virtual void updateDisplay();
	
	public:
		SFMLClient();
};
}
#endif
