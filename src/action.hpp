#pragma once

#include "command.hpp"
#include "levelState.hpp"

namespace engine {

	class Action{
	
	public:
		virtual ~Action() =0;
		virtual void apply(state::LevelState& levelState, bool notify) =0;
	};
}
