#ifndef SFMLSurface_H
#define SFMLSurface_H
#include <SFML/Graphics.hpp>
#include "surface.hpp"

class SFMLSurface : public Surface, public sf::Drawable, public sf::Transformable {
	
	protected:
		sf::VertexArray vertices;
		sf::Texture tileset;

	public:
		virtual void loadTexture(const char* tileset);
		virtual void setSpriteCount(int n);
		virtual void setSpriteLocation(int i, int x, int y);
		virtual void setSpriteTexture(int i, const StaticTile* staticTile);
	
	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
