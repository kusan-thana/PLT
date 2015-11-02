#include "levelState.hpp"
#include <iostream>

/**
 * LevelState Class
**/

using namespace state;

LevelState::LevelState() : characters(*this), grid(*this) {
}
void LevelState::setElementFactory(ElementFactory* factory){
	
	characters.setElementFactory(factory);
	grid.setElementFactory(factory);
}
ElementGrid& LevelState::getElementGrid(){
		
	return grid;
}
const ElementGrid& LevelState::getElementGrid() const{
	
	return grid;
}
ElementList& LevelState::getCharacters(){

	return characters;
}
void LevelState::loadLevel(const char* file_name){

	grid.load(file_name);
}
