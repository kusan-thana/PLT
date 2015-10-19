#include "sfmlsurface.hpp"

#include <iostream>
/**
 * SFMLSurface Class
**/

void SFMLSurface::loadTexture(const char* tileset){

	if (!this->tileset.loadFromFile(tileset))
		std::cout << "Texture Error.." << std::endl;
}
void SFMLSurface::setSpriteLocation(int i, int x, int y){
	
	 //~ quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
     //~ quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
     //~ quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
     //~ quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
}
void SFMLSurface::setSpriteTexture(int i, const StaticTile* staticTile){

	sf::Vertex* quad = &vertices[i * 4];
	
	int x = staticTile->getX();
	int y = staticTile->getY();
	int width = staticTile->getWidth();
	int height = staticTile->getHeight();
	
	quad[0].texCoords = sf::Vector2f(x, y);
	quad[1].texCoords = sf::Vector2f(x + width, y);
	quad[2].texCoords = sf::Vector2f(x + width, y + height);
	quad[3].texCoords = sf::Vector2f(x, y + height);
}
