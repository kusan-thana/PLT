#include "tileSet.hpp"

/**
 * TileSet Class
**/

using namespace render;

TileSet::~TileSet(){
}
void TileSet::setStaticTile(render::StaticTile staticTile){
	
	this->staticTiles.push_back(staticTile);
}
