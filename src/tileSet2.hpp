#ifndef TileSet2_H
#define TileSet2_H
#include <vector>
#include <string>
#include "tileSet.hpp"
#include "tile.hpp"
#include "staticTile.hpp"

namespace render {
	
class TileSet2 : public TileSet {
	
	enum TileID2 { HERO=0, WIZARD=1, MINION=2, INACTIVE_HERO = 3, INACTIVE_WIZARD = 4, INACTIVE_MINION = 5};

	protected:
		std::vector<render::Tile*> tiles;
		const char* file_name;
		int widthCell;
		int heightCell;

	public:
		TileSet2();
		virtual int getCellWidth() const;
		virtual int getCellHeight() const;
		const char* getImageFile() const;
		const Tile* getElementTile(const state::Element* element) const;
};
}
#endif
