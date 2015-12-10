#ifndef AI_H
#define AI_H

#include "state.hpp"
#include "engine.hpp"

namespace ai {
	class AI;
	class DumbAI;
}

static const std::vector<state::Direction> directions{ state::Direction::NONE, state::Direction::NORTH, state::Direction::SOUTH, state::Direction::EAST, state::Direction::WEST };

#include "generated/ai.h"



#endif
