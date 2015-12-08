#include "ai.hpp"
#include <string>
/**
 * Coords Class
**/
#include "element.hpp"

using namespace ai;

Coords::Coords(int x, int y) : x(x), y(y), value(0){
}
Coords::Coords(int x, int y, state::Direction direction) : value(0){
	
	if(direction == state::Direction::NONE){
		
		this->x = x;
		this->y = y;
	}
	if(direction == state::Direction::NORTH){
		
		this->x = x-1;
		this->y = y;
	}
	if(direction == state::Direction::SOUTH){
		
		this->x = x+1;
		this->y = y;
	}
	if(direction == state::Direction::WEST){
		
		this->x = x;
		this->y = y-1;
	}
	if(direction == state::Direction::EAST){
		
		this->x = x;
		this->y = y+1;
	} 
}
Coords::Coords(int x, int y, state::Direction direction, int value) : value(value){
	
	if(direction == state::Direction::NONE){
		
		this->x = x;
		this->y = y;
	}
	if(direction == state::Direction::NORTH){
		
		this->x = x-1;
		this->y = y;
	}
	if(direction == state::Direction::SOUTH){
		
		this->x = x+1;
		this->y = y;
	}
	if(direction == state::Direction::WEST){
		
		this->x = x;
		this->y = y-1;
	}
	if(direction == state::Direction::EAST){
		
		this->x = x;
		this->y = y+1;
	}

}
bool Coords::operator<(const Coords& coords) const
{
  return (*this).value < coords.value;
}
