#include "pathMap.hpp"
#include <iostream>
#include <cmath>

/**
 * PathMap Class
**/

using namespace ai;

PathMap::PathMap(){
}
PathMap::~PathMap(){
}
int PathMap::getWidth() const{
	
	return this->width;
}
int PathMap::getHeight() const{
	
	return this->height;
}
int PathMap::getWeight(int x, int y, state::Direction) const{
	
	return this->weights[y + x*width];
}
int* PathMap::getWeights() const{
	
	return this->weights;
}
void PathMap::setWeight(int x, int y, int w){
	
	this->weights[y + x*width] = w;
}
void PathMap::computeWeights(const state::ElementGrid& grid, state::Element* element){
	
	this->width = grid.getWidth();
	this->height = grid.getHeight();
	this->weights = new int[width*height];
	
	int x_elem = element->getX();
	int y_elem = element->getY();
	std::cout << element->getX() << std::endl;
	std::cout << element->getY() << std::endl;
	
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			
			int x_tmp = abs(i-x_elem);
			int y_tmp = abs(j-x_elem);
			
			if(x_tmp >= y_tmp)
				weights[j + i*width] = x_tmp;
			
			else 	weights[j + i*width] = y_tmp;
		}
	}
}
void PathMap::display(){
	std::cout << "---Hero Path Map (initial position)---" << std::endl;
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			
			std::cout << weights[j + i*width];
			
		}
		std::cout << std::endl;
	}
}



