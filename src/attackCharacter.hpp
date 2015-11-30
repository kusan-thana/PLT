#pragma once
#include "action.hpp"
#include "mobileElement.hpp"
namespace engine{
	class AttackCharacter :	public Action
	{
		state::MobileElement* attacker;
		state::MobileElement* target;
		state::LevelState& levelState;

	public:
		AttackCharacter(state::MobileElement* attacker, state::MobileElement* target, state::LevelState& levelState);
		~AttackCharacter();
		void apply(state::LevelState&);
	};
}
