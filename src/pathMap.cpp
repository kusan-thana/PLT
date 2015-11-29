#include "pathMap.hpp"
#include <iostream>
#include <queue>
#include <cmath>
#include "coords.hpp"

/**
 * PathMap Class
**/

using namespace ai;

PathMap::PathMap(state::LevelState& levelState, state::Element* element) : levelState(levelState), width(levelState.getElementGrid().getWidth()), height(levelState.getElementGrid().getHeight()){
	
	elements.push_back(element);
	weights = new int[width*height];
}
PathMap::~PathMap(){
	
	elements.clear();
	delete(this->weights);
}
void PathMap::addElement(state::Element* element){
	
	elements.push_back(element);
}
int PathMap::getWidth() const{
	
	return this->width;
}
int PathMap::getHeight() const{
	
	return this->height;
}
int* PathMap::getWeghts() const{
	
	return weights;
}
int PathMap::getMetadata(int x, int y) const{
	
	return weights[x*width + y]; 
}
int PathMap::getMetadata(int x, int y, state::Direction direction) const{
	
	Coords coords(x, y, direction);
	
	return weights[coords.x*width + coords.y]; 
}
void PathMap::setMetadata(int x, int y, int value){

	weights[x*width + y] = value;
}
void PathMap::setMetadata(int x, int y, int value, state::Direction direction){

	Coords coords(x, y, direction);

	weights[coords.x*width + coords.y] = value;
}
void PathMap::initMetadata(int defaultValue){
	
	for(int i=0; i<width*height; i++){
		
		weights[i] = defaultValue;
	}
}
bool PathMap::isValid(int x, int y, state::Direction direction) const{

	Coords coords(x, y, direction);
	
	if(coords.x < width && coords.x >= 0 && coords.y < height && coords.y >= 0){
		return true;
	}
}
int PathMap::relax (int x, int y, state::Direction direction){
	
	Coords coords(x, y, direction);
	int i = coords.x;
	int j = coords.y;
	
	state::TypeID type = levelState.getElementGrid().getElement(i,j)->getTypeID();

	if ( type != state::SPACE || levelState.getElementList().getElement(i,j) && this->weights[i*width + j] !=0)
	{
		return false;
	}

	int a = getMetadata(x ,y);
	int b = getMetadata(x, y, direction);
	if((a+1) < b) {
		setMetadata(x, y, a+1, direction);
		return a+1;
	}
	return 0;
}
void PathMap::dijsktra(){
	
	initMetadata(999);
	
	if(!elements.empty()){
		
		std::priority_queue<Coords> todo;
		
		for (state::Element* element : elements){
			int x = element->getX();
			int y = element->getY();
			setMetadata(x, y, 0);
			todo.push(Coords(x, y));
		}

		while(!todo.empty()) {

			Coords coords = todo.top();
			todo.pop();
			int i = coords.x;
			int j = coords.y;

			for (state::Direction direction : directions) {

				if(isValid(i, j, direction)) {
					int value = relax (i, j, direction);
					if (value) {
						todo.push(Coords(i, j, direction, value));
					}
				}
			}
		}
	}
}
void PathMap::display(){
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "-----------ENLARGE THE BASH WINDOW BEFORE RUNNING!!-------------" << std::endl;
	std::cout << "--------------Path Map using Dijkstra algorithm-----------------" << std::endl;
	std::cout << "------------------Display from SFMLClient-----------------------" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			
			std::cout.width(4); std::cout << std::left << weights[j + i*width];
			
		}
		std::cout << std::endl;
	}
}



