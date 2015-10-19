#include "statictile.hpp"

/**
 * StaticTile Class
**/
StaticTile::StaticTile() {
	   
	this->vertices.setPrimitiveType(sf::Quads);
	this->vertices.resize(4);
}
bool StaticTile::isAnimated() const{
	
	return false;
}
void StaticTile::setX(int x){
	
	this->x = x;
}
void StaticTile::setY(int y){
	
	this->y = y;
}
void StaticTile::setWidth(int width){
	
	this->width = width;
}
void StaticTile::setHeight(int height){
	
	this->height = height;
}
