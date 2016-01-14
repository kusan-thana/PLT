#ifndef AI_H
#define AI_H

#include <thread>
#include "state.hpp"
#include "engine.hpp"

namespace ai {
	class AI;
	class DumbAI;
	class HeuristicAI;
	class PathMap;
	class Coords;
}

static const std::vector<state::Direction> directions{ state::Direction::NONE, state::Direction::NORTH, state::Direction::SOUTH, state::Direction::EAST, state::Direction::WEST };

#include "server.hpp"

#include "../generated/ai.h"



#endif
