#ifndef TileSet_H
#define TileSet_H
#include <vector>
#include "statictile.hpp"
#include "element.hpp"
#include "tile.hpp"

class TileSet {

	protected:
		std::vector<StaticTile> staticTiles;

	public:
		const Tile* const getElementTile(const Element* element);
};

#endif



