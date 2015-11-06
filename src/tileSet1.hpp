#ifndef TileSet1_H
#define TileSet1_H
#include <vector>
#include <string>
#include "tileSet.hpp"
#include "tile.hpp"
#include "staticTile.hpp"

namespace render {
	
class TileSet1 : public TileSet {
	
	enum TileID { TREE=0, WATER=1, GRASS=2, FIR=3 };

	protected:
		std::vector<render::Tile*> tiles;
		const char* file_name;
		int widthCell;
		int heightCell;

	public:
		TileSet1();
		virtual int getCellWidth() const;
		virtual int getCellHeight() const;
		const char* getImageFile() const;
		const Tile* getElementTile(const state::Element* element) const;
};
}
#endif
