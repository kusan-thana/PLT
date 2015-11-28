#ifndef Surface_H
#define Surface_H
#include "staticTile.hpp"

class Surface {
	
	public:
		virtual void clear() =0;
		virtual void loadTexture(const char* tileset) =0;
		virtual void setSpriteCount(int n) =0;
		virtual void setSpriteLocation(int i, int x, int y) =0;
		virtual void setSpriteTexture(int i, const render::StaticTile* staticTile) =0; 
		Surface* getSurface();
};

#endif
