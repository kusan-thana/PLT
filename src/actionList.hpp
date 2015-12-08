#pragma once

#include "levelState.hpp"
#include "action.hpp"
#include <vector>

namespace engine {

	class ActionList{
		
		protected:
			state::LevelState& levelState;
			std::vector<Action*> actions; 
			
		public:
			ActionList(state::LevelState& levelState);
			int size() const;
			Action* get(int i) const;
			void apply();
			void add(Action* action);
			void clear();
		};
}
