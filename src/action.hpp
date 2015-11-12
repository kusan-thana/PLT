#pragma once

#include "levelState.hpp"

namespace engine {

	class Action{
	
	public:
		virtual ~Action();
		virtual void apply(state::LevelState& levelState) =0;
	};
}
