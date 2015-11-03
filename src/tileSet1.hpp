#ifndef TileSet1_H
#define TileSet1_H
#include <map>
#include <vector>
#include <string>
#include "tileSet.hpp"
#include "tile.hpp"
#include "staticTile.hpp"

namespace render {
	
class TileSet1 : public TileSet {
	
	enum TileID { TREE=0, WATER=1, GRASS=2, FIR=3 };

	protected:
		//std::map<std::string,render::Tile*> tiles;
		std::vector<render::Tile*> tiles;
		const char* file_name;

	public:
		TileSet1();
		const char* getImageFile();
		const Tile* getElementTile(const state::Element* element) const;
};
}
#endif
