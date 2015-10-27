#ifndef Layer_H
#define Layer_H

#include "surface.hpp"
#include "tileSet.hpp"

namespace render {

class Layer {
	
	protected:
		Surface* surface;
		const render::TileSet* tileSet;
		
	public:
		Layer();
		virtual ~Layer();
		void setTileSet(const render::TileSet* tileSet);
		void setSurface(Surface* surface);
};
}
#endif
