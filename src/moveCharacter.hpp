#pragma once
#include "action.hpp"
namespace engine {

	class MoveCharacter : public Action
		
	{
	protected: 
		int dx;
		int dy;
		state::Element* tile;
	public:
		MoveCharacter();
		~MoveCharacter();
		void setCoords(int dx, int dy);
		void apply(state::LevelState& levelState);
		
	};
}
