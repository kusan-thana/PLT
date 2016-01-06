#ifndef State_H
#define State_H
#include <vector>
#include <unordered_map>

namespace state {
	class Element;
	class MobileElement;
	class StaticElement;
	class PlayerCharacter;
	class Monster;
	class Obstacle;
	class Space;
	class ElementFactory;
	class AElementAlloc;
	template<class E, typename ID>
	class ElementAlloc;
	class Observable;
	class LevelStateObserver;
	class LevelStateEvent;
	class LevelListEvent;
	class ElementList;
	class ElementGrid;
	class LevelState;
	class State;
	class WorldState;
	class ElementListWorld;
	class ElementWorld;
	class ElementLevel;
}

#include "../generated/state.h"
#include "elementAlloc.tpp"		//Implementation file


#endif
