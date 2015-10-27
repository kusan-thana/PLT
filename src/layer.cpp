#include "layer.hpp"

/**
 * Layer Class
**/

using namespace render;

Layer::Layer() {
}
Layer::~Layer(){
}
void Layer::setTileSet(const render::TileSet* tileSet){
	
	this->tileSet = tileSet;
}
void Layer::setSurface(Surface* surface){
	
	this->surface = surface;
}
