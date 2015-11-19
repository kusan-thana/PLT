#ifndef DumbAI_H
#define DumbAI_H

#include "ai.hpp"
#include "levelState.hpp"
#include "commandSet.hpp"
#include "levelStateEvent.hpp"

namespace ai {
	
class DumbAI : public AI {
	
	protected:
		void dumbMove(int idx, engine::CommandSet& commands);

	public:
		DumbAI(const state::LevelState& mainLevelState);
		void run(engine::Engine& engine);
};
}
#endif
