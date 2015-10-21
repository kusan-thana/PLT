#include "layer.hpp"

/**
 * Layer Class
**/

Layer::Layer() {
}
Layer::~Layer(){
}
void Layer::setTileSet(const TileSet* tileSet){
	
	this->tileSet = tileSet;
}
void Layer::setSurface(Surface* surface){
	
	this->surface = surface;
}
