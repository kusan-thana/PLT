#ifndef Surface_H
#define Surface_H
#include "statictile.hpp"

class Surface {
	
	public:
		virtual void loadTexture(const char* tileset) =0;
		virtual void setSpriteLocation(int i, int x, int y) =0;
		virtual void setSpriteTexture(int i, const StaticTile* staticTile) =0; 
};

#endif
