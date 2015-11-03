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
		virtual const char* getImageFile() =0;
		virtual const Tile* getElementTile(const state::Element* element) const =0;
};
}
#endif



