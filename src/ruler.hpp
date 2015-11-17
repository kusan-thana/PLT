#pragma once

#include "levelState.hpp"
#include "commandSet.hpp"
#include "actionList.hpp"

namespace engine {
	class Ruler
	{
		protected:
			const CommandSet& commands;
			state::LevelState& curr_LevelState;
			ActionList actions;
			
		public:
			Ruler(CommandSet&, state::LevelState&);
			~Ruler();
			void apply();
	};
}
