#ifndef Layer_H
#define Layer_H

#include "surface.hpp"
#include "tileset.hpp"

class Layer {
	
	protected:
		Surface* surface;
		const TileSet* tileSet;
		
	public:
		Layer();
		virtual ~Layer();
		void setTileSet(const TileSet* tileSet);
		void setSurface(Surface* surface);
};

#endif
