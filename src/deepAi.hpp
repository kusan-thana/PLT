#ifndef DeepAI_H
#define DeepAI_H
#include "ai.hpp"

namespace ai {
	
class DeepAI : public AI {
	
	protected:

	public:
		DeepAI(const state::LevelState& manLevelState);
		void run(engine::Engine& engine);
};
}
#endif
