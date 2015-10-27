#ifndef TileSet_H
#define TileSet_H
#include <vector>
#include "staticTile.hpp"
#include "element.hpp"
#include "tile.hpp"

namespace render {

class TileSet {

	protected:
		std::vector<render::StaticTile> staticTiles;

	public:
		~TileSet();
		void setStaticTile(render::StaticTile staticTile);
		const render::Tile* const getElementTile(const state::Element* element);
};
}
#endif



