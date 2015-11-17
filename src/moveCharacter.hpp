#pragma once
#include "action.hpp"


namespace engine {

	class MoveCharacter : public Action
	{
	protected: 
		state::Element* character;
		state::LevelState& levelState;

		int x;
		int y;

	public:
		MoveCharacter(state::Element* character, int x, int y, state::LevelState& levelState);
		~MoveCharacter();
		void apply(state::LevelState&);

	};
}
