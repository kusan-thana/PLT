#ifndef LevelListEvent_H
#define LevelListEvent_H
#include "levelStateEvent.hpp"
#include "elementList.hpp"

namespace state {

class LevelListEvent : public LevelStateEvent{

	public:
		const ElementList& list;
		int idx;
		
		LevelListEvent(const ElementList& list, int idx);
};
}
#endif



