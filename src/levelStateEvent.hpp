#ifndef LevelStateEvent_H
#define LevelStateEvent_H

enum LevelStateEventID { ALL_CHANGED=1, LEVEL_CHANGED=2, EPOCH_CHANGED=3, LIST_CHANGED=4 };

namespace state {

// forward declared dependencies
class LevelState;

class LevelStateEvent {

	protected:
		LevelStateEventID id;
	public:
		const LevelState& levelState;
		
		LevelStateEvent(const LevelState& levelState, LevelStateEventID id);
		bool operator==(LevelStateEventID id) const;
		bool operator!=(LevelStateEventID id) const;
};
}
#endif



