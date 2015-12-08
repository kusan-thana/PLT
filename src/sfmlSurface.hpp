#ifndef SFMLSurface_H
#define SFMLSurface_H
#include <SFML/Graphics.hpp>
#include "surface.hpp"

namespace render {
	
class SFMLSurface : public Surface, public sf::Drawable, public sf::Transformable {
	
	protected:
		sf::VertexArray vertices;
		sf::Texture tileset;
		int widthSprite;
		int heigthSprite;

	public:
		SFMLSurface();
		virtual void clear();
		virtual void loadTexture(const char* tileset);
		virtual void setSpriteCount(int n);
		virtual void setSpriteLocation(int i, int x, int y);
		virtual void setSpriteTexture(int i, const render::StaticTile* staticTile);
		void setSpriteWidth(int widthSprite);
		void setSpriteHeight(int heigthSprite);
		SFMLSurface& getSfmlSurface() ;
	
	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
}
#endif
