#include "tileSet1.hpp"
#include <iostream>

#include "staticTile.hpp"
#include "obstacle.hpp"
#include "space.hpp"
/**
 * TileSet1 Class
**/

using namespace render;

TileSet1::TileSet1() : file_name("../res/images/dungeon.gif"), widthCell(32), heightCell(32) {

	tiles.push_back(new render::StaticTile(160,128,32,32));	//TREE
	tiles.push_back(new render::StaticTile(160,160,32,32));	//WATER
	tiles.push_back(new render::StaticTile(0,160,32,32));	//GRASS
	tiles.push_back(new render::StaticTile(224,128,32,32));	//FIR
}
int TileSet1::getCellWidth() const{
	
	return widthCell;
}
int TileSet1::getCellHeight() const{

	return heightCell;
}
const char* TileSet1::getImageFile() const{

	return file_name;
}
const Tile* TileSet1::getElementTile(const state::Element* element) const {
	
	if(element->getTypeId() == state::SPACE){
		
		switch(((state::Space*)element)->getSpaceTypeID())
		{
			case(SpaceTypeID::GRASS):
			{
				return tiles[TileID1::GRASS];
			}
			break;
		}
	}
	if(element->getTypeId() == state::OBSTACLE){
		
		switch(((state::Obstacle*)element)->getObstacleTypeID())
		{
			case(ObstacleTypeID::TREE):
			{
				return tiles[TileID1::TREE];
			}
			break;
			case(ObstacleTypeID::WATER):
			{
				return tiles[TileID1::WATER];
			}
			break;
			case(ObstacleTypeID::FIR):
			{
				return tiles[TileID1::FIR];
			}
			break;
		}
	}
}
