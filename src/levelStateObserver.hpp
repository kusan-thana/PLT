#ifndef LevelStateObserver_H
#define LevelStateObserver_H
#include "levelStateEvent.hpp"

namespace state {

class LevelStateObserver {

	public:
		virtual void levelStateChanged(const LevelStateEvent& levelStateEvent) =0;
};
}
#endif



