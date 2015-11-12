#pragma once

#include "levelState.hpp"
#include "commandSet.hpp"
#include "actionList.hpp"

namespace engine {
	class Ruler
	{
		protected:
			const CommandSet& commands;
			const state::LevelState& curr_LevelState;
			ActionList actions;
			//int &a;
			
		public:
			Ruler(CommandSet&, state::LevelState&);
			~Ruler();
			void apply();
	};
}
