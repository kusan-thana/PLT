#include "levelStateEvent.hpp"
#include "levelState.hpp"

/**
 * LevelStateEvent Class
**/

using namespace state;

LevelStateEvent::LevelStateEvent(const LevelState& levelState, LevelStateEventID id) : levelState(levelState), id(id){
}
bool LevelStateEvent::operator==(LevelStateEventID id) const{
	
	if(this->id == id)		return true;
	else 					return false;
}
bool LevelStateEvent::operator!=(LevelStateEventID id) const{
	
	if(this->id != id)		return true;
	else 					return false;
}
