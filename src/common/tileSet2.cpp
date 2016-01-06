#include "render.hpp"
#include <iostream>

#include "state.hpp"

/**
 * TileSet2 Class
**/

using namespace render;

TileSet2::TileSet2() : file_name("../res/images/characters.png"), widthCell(32), heightCell(32) {

	tiles.push_back(new render::StaticTile(64,0,32,40));	//HERO
	tiles.push_back(new render::StaticTile(64,490,32,40));	//WIZARD
	tiles.push_back(new render::StaticTile(0,980,45,42));	//MINION
	tiles.push_back(new render::StaticTile(318,0,32,40));	//INACTIVE_HERO
	tiles.push_back(new render::StaticTile(318,490,32,40));	//INACTIVE_HERO
	tiles.push_back(new render::StaticTile(256,980,45,42));	//INACTIVE_HERO
}
int TileSet2::getCellWidth() const{
	
	return widthCell;
}
int TileSet2::getCellHeight() const{

	return heightCell;
}
const char* TileSet2::getImageFile() const{

	return file_name;
}
const Tile* TileSet2::getElementTile(const state::Element* element) const {
	
	switch(element->getTypeID())
	{
	case(state::TypeID::HERO):
		{
			if(!((state::MobileElement*)element)->getTurnPlayed())
				return tiles[TileID2::HERO];
			else
				return tiles[TileID2::INACTIVE_HERO];
		}
		break;
	case(state::TypeID::WIZARD):
		{
			if(!((state::MobileElement*)element)->getTurnPlayed())
				return tiles[TileID2::WIZARD];
			else
				return tiles[TileID2::INACTIVE_WIZARD];
		}
		break;
	case(state::TypeID::MINION):
		{
			if(!((state::MobileElement*)element)->getTurnPlayed())
				return tiles[TileID2::MINION];
			else
				return tiles[TileID2::INACTIVE_MINION];
		}
		break;
	}
}
