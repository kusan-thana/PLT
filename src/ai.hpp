#ifndef AI_H
#define AI_H

#include "levelState.hpp"
#include "commandSet.hpp"
#include "engine.hpp"

namespace ai {
	
class AI {
	
	protected:
		const state::LevelState mainLevelState;

	public:
		AI(const state::LevelState& mainLevelState);
		virtual ~AI();
		virtual void run(engine::Engine& engine) =0;
};
}
#endif
