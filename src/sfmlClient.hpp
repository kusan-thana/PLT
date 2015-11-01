#ifndef SFMLClient_H
#define SFMLClient_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "client.hpp"
#include "sfmlSurface.hpp"

namespace client {

class SFMLClient : public Client {

	protected:
		sf::RenderWindow window;
		std::vector<SFMLSurface*> sfmlSurfaces;
		
		void init();
		virtual bool acquireControls();
		//virtual void stateChanged();
		virtual void updateDisplay();
	
	public:
		SFMLClient();
};
}
#endif
