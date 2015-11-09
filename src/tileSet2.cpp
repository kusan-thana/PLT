#include "tileSet2.hpp"
#include <iostream>

#include "staticTile.hpp"
#include "obstacle.hpp"
#include "space.hpp"
/**
 * TileSet2 Class
**/

using namespace render;

TileSet2::TileSet2() : file_name("../res/images/samu.bmp"), widthCell(32), heightCell(40) {

	tiles.push_back(new render::StaticTile(64,0,32,40));	//HERO
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
		case(TypeID::HERO):
		{
			return tiles[TileID::HERO];
		}
		break;
	}
	
}
