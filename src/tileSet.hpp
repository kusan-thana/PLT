#ifndef TileSet_H
#define TileSet_H
#include <vector>
#include "staticTile.hpp"
#include "tile.hpp"
#include "element.hpp"


namespace render {

class TileSet {

	public:
		~TileSet();
		virtual int getCellWidth() const =0;
		virtual int getCellHeight() const =0;
		virtual const char* getImageFile() const =0;
		virtual const render::Tile* getElementTile(const state::Element* element) const =0;

};
}
#endif



