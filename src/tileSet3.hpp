#ifndef TileSet3_H
#define TileSet3_H
#include <vector>
#include <string>
#include "tileSet.hpp"
#include "tile.hpp"
#include "staticTile.hpp"

namespace render {
	
class TileSet3 : public TileSet {
	
	enum TileID { RED=0, YELLOW=1, GREEN=2 };

	protected:
		std::vector<render::Tile*> tiles;
		const char* file_name;
		int widthCell;
		int heightCell;

	public:
		TileSet3();
		virtual int getCellWidth() const;
		virtual int getCellHeight() const;
		const char* getImageFile() const;
		const Tile* getElementTile(const state::Element* element) const;
};
}
#endif
