#include "state.hpp"

/**
 * LevelListEvent Class
**/

using namespace state;

LevelListEvent::LevelListEvent(const ElementList& list, int idx) : LevelStateEvent(list.getLevelState(), LIST_CHANGED), list(list), idx(idx){
}
