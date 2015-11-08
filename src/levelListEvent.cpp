#include "levelListEvent.hpp"

/**
 * LevelListEvent Class
**/

using namespace state;

//~ LevelListEvent::LevelListEvent(const ElementList& list, int idx) : LevelStateEvent(levelState, id), list(list), idx(idx){
//~ }
LevelListEvent::LevelListEvent(const ElementList& list, int idx) : LevelStateEvent(list.getLevelState(), id), list(list), idx(idx){
}
