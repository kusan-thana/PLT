#ifndef IncEpoch_H
#define IncEpoch_H
#include "action.hpp"
#include "levelState.hpp"

namespace engine {
	
class IncEpoch : public Action {
	
	protected:

	public:
		IncEpoch();
		virtual void apply(state::LevelState& levelState);
	
};
}
#endif
