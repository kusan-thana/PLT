#pragma once

#include "levelState.hpp"
#include "commandSet.hpp"

namespace engine {
	class Ruler
	{
		protected:
			const CommandSet& commands;
			const state::LevelState& curr_LevelState;
			
		public:
			Ruler(CommandSet&, const state::LevelState&);
			~Ruler();
			void apply();
	};
}
