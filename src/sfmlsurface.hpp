#ifndef SFMLSurface_H
#define SFMLSurface_H
#include <SFML/Graphics.hpp>
#include "surface.hpp"

class SFMLSurface : public Surface {
	
	protected:
		sf::VertexArray vertices;
		sf::Texture tileset;

	public:
		virtual void loadTexture(const char* tileset);
		virtual void setSpriteLocation(int i, int x, int y);
};

#endif
