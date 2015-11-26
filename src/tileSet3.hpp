#ifndef TileSet3_H
#define TileSet3_H
#include <vector>
#include <string>
#include "tileSet.hpp"
#include "tile.hpp"
#include "staticTile.hpp"
#include "cursor.hpp"

namespace guiRender {
	
class TileSet3 : public render::TileSet {
	
	enum TileID { RED=0, YELLOW=1, GREEN=2, HEALTH_BAR_RED = 3, HEALTH_BAR_GREEN = 4 };

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
		const render::Tile* getElementTile(const state::Element* element) const;
		const render::Tile* getElementTile(gui::Cursor& cursor) const;
};
}
#endif
