#include "tileSet3.hpp"
#include <iostream>

#include "staticTile.hpp"
#include "obstacle.hpp"
#include "space.hpp"
/**
 * TileSet3 Class
**/

using namespace guiRender;

TileSet3::TileSet3() : file_name("../res/images/ryg.png"), widthCell(32), heightCell(32) {

	tiles.push_back(new render::StaticTile(0,0,32,32));		//RED
	tiles.push_back(new render::StaticTile(32,0,32,32));	//YELLOW
	tiles.push_back(new render::StaticTile(64,0,32,32));	//GREEN

}
int TileSet3::getCellWidth() const{
	
	return widthCell;
}
int TileSet3::getCellHeight() const{

	return heightCell;
}
const char* TileSet3::getImageFile() const{

	return file_name;
}
const render::Tile* TileSet3::getElementTile(const state::Element* element) const {
	
	switch(((state::Space*)element)->getSpaceTypeID())
	{
		case(SpaceTypeID::RED):
		{
			return tiles[TileID::RED];
		}
		break;
		case(SpaceTypeID::YELLOW):
		{
			return tiles[TileID::YELLOW];
		}
		break;
		case(SpaceTypeID::GREEN):
		{
			return tiles[TileID::GREEN];
		}
		break;
	}
}
const render::Tile* TileSet3::getElementTile(gui::Cursor& cursor) const{
	
	if(cursor.getActive())
		return tiles[TileID::YELLOW];
	
	else
		return tiles[TileID::RED];
}
