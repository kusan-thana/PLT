#ifndef PathMap_H
#define PathMap_H
#include "levelState.hpp"
#include <queue>
#include <vector>
#include "element.hpp"
#include "coords.hpp"
#include <vector>

#include "generated/ai.h"

namespace ai {

	static const std::vector<state::Direction> directions{ state::Direction::NONE, state::Direction::NORTH, state::Direction::SOUTH, state::Direction::EAST, state::Direction::WEST };
}

#endif
