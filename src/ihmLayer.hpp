#ifndef IHMLayer_H
#define IHMLayer_H
#include "ihmObserver.hpp"
#include "surface.hpp"
#include "tileSet.hpp"
#include "ihmEvent.hpp"

namespace ihmRender {
	
class IHMLayer : public ihm::IHMObserver{
	
	protected:
		Surface* surface;
		const render::TileSet* tileSet;
		
	public:
		IHMLayer();
		virtual ~IHMLayer();
		const render::TileSet* getTileSet() const;
		void setTileSet(const render::TileSet* tileSet);
		void setSurface(Surface* surface);
		virtual void ihmChanged(const ihm::IHMEvent& e);
};
}
#endif
