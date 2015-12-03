#pragma once
#include "action.hpp"
#include "mobileElement.hpp"
namespace engine{
	class AttackCharacter :	public Action
	{
		state::MobileElement* attacker;
		state::MobileElement* target;

	public:
		AttackCharacter(state::MobileElement* attacker, state::MobileElement* target);
		~AttackCharacter();
		void apply(state::LevelState&);
	};
}
