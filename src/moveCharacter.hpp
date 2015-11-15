#pragma once

#include "action.hpp"
#include "levelState.hpp"

#include <vector>

namespace engine {

	class MoveCharacter : public Action{
		
		protected:
			int idx;
			int dx;
			int dy;
			int dpos;
			state::Direction newDirection;
			
		public:
			MoveCharacter(int idx);
			void setCoords(int dx, int dy, int dpos);
			void setDirection(state::Direction next);
			void apply(state::LevelState& levelState);
		};
}
