#ifndef Layer_H
#define Layer_H
#include "levelStateObserver.hpp"
#include "surface.hpp"
#include "tileSet.hpp"

namespace render {

class Layer : public state::LevelStateObserver{
	
	public:
		Surface* surface;
	protected:
		//~ Surface* surface;
		const render::TileSet* tileSet;
		
	public:
		Layer();
		virtual ~Layer();
		const TileSet* getTileSet() const;
		void setTileSet(const render::TileSet* tileSet);
		void setSurface(Surface* surface);
};
}
#endif
