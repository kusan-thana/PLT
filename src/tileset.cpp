#include "tileset.hpp"

/**
 * TileSet Class
**/

TileSet::TileSet() {
}
TileSet::~TileSet(){
}
void TileSet::setStaticTile(StaticTile staticTile){
	
	this->staticTiles.push_back(staticTile);
}
