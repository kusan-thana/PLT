#include "pathMap.hpp"
#include <iostream>

/**
 * PathMap Class
**/

using namespace ai;

PathMap::PathMap(){
}
PathMap::~PathMap(){
}
int PathMap::getWidth() const{
	
	return width;
}
int PathMap::getHeight() const{
	
	return height;
}
int PathMap::getWeight(int x, int y, state::Direction) const{
	return 0;
}
int* PathMap::getWeights() const{
	
	return weights;
}
void PathMap::setWeight(int x, int y, int w){
	
	
}
