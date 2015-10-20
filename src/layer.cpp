#include "layer.hpp"

/**
 * Layer Class
**/

Layer::Layer() {

	this->surface = new SFMLSurface();
}
Layer::~Layer(){
}
void Layer::setSurface(Surface* surface){
	
	this->surface = surface;
}
