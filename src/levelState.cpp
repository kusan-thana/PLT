#include "state.hpp"
#include <iostream>

/**
 * LevelState Class
**/

using namespace state;

LevelState::LevelState() : characters(*this), grid(*this), turnToPlay(state::PLAYER), epoch(0){
}
void LevelState::setElementFactory(ElementFactory* factory){
	
	characters.setElementFactory(factory);
	grid.setElementFactory(factory);
}
const ElementGrid& LevelState::getElementGrid() const{
	
	return grid;
}
ElementGrid& LevelState::getElementGrid(){
		
	return grid;
}
const ElementList& LevelState::getElementList() const{
	
	return characters;
}
ElementList& LevelState::getElementList(){

	return characters;
}
void LevelState::loadLevel(const char* file_name){

	grid.load(file_name);
}
int LevelState::getEpoch() {

	return epoch;
}
void LevelState::setEpoch(int epoch) {

	this->epoch = epoch;
}

TurnToPlay state::LevelState::getTurnToPlay() const
{
	return turnToPlay;
}

void LevelState::setTurnToPlay(TurnToPlay turnToPlay)
{
	this->turnToPlay = turnToPlay;
}
LevelState* LevelState::clone() const{

	LevelState* clone = new LevelState();
	
	clone->characters.copy(this->characters);
	clone->grid.copy(this->grid);
	clone->epoch = this->epoch;
	clone->turnToPlay = this->turnToPlay;
	
	return clone;
}
void LevelState::copy(const LevelState& levelState){
	
	this->characters.copy(levelState.characters);
	this->grid.copy(levelState.grid);
	this->epoch = levelState.epoch;
	this->turnToPlay = levelState.turnToPlay;
}
