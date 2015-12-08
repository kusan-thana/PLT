#pragma once
#include "action.hpp"

namespace engine {

	class EndTurnTeam : public Action
	{
	public:
		EndTurnTeam();
		~EndTurnTeam();
		void apply(state::LevelState& levelState);

	};
}
