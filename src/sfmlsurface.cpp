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
	
	
}
