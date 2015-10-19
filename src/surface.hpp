#ifndef Surface_H
#define Surface_H
#include "statictile.hpp"

class Surface {
	
	public:
		virtual void loadTexture(const char* tileset) =0;
		virtual void setSpriteLocation(int i, const StaticTile* texture) =0; 
};

#endif
