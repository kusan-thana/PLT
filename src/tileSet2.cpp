#include "tileSet2.hpp"
#include <iostream>

#include "staticTile.hpp"
#include "obstacle.hpp"
#include "space.hpp"
/**
 * TileSet2 Class
**/

using namespace render;

//~ TileSet2::TileSet2() : file_name("../res/images/samu_mask.png"), widthCell(32), heightCell(32) {
TileSet2::TileSet2() : file_name("../res/images/characters.png"), widthCell(32), heightCell(32) {

	tiles.push_back(new render::StaticTile(64,0,32,40));	//HERO
	tiles.push_back(new render::StaticTile(64,490,32,40));	//WIZARD
	
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
			return tiles[TileID::HERO];
		}
		break;
	case(state::TypeID::WIZARD):
		{
			return tiles[TileID::WIZARD];
		}
		break;
	}
}
