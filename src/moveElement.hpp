#pragma once

#include "action.hpp"
#include "levelState.hpp"

#include <vector>

namespace engine {

	class MoveElement : public Action{
		
		protected:
			int dx;
			int dy;
			state::Element* tile;

		public:
			MoveElement(state::Element* tile);
			MoveElement(engine::MoveElement* moveElement);
			void setCoords(int dx, int dy);
			void apply(state::LevelState& levelState);
			void setTile(state::Element* tile);
		};
}