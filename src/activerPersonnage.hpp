#pragma once
#include "action.hpp"

namespace engine {

	class ActiverPersonnage : public Action
	{
	protected: 
		state::Element* perso;

	public:
		ActiverPersonnage(state::Element* perso);
		~ActiverPersonnage();
		void apply(state::LevelState& levelState);

	};
}
