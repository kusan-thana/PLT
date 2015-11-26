#pragma once
#include "action.hpp"
#include "levelState.hpp"

namespace engine{
	class EndTurnAction : public Action
	{
	protected:
		state::Element* character;
	public:
		EndTurnAction(state::Element* character);
		~EndTurnAction();
		void apply(state::LevelState& levelState);
		};
}
