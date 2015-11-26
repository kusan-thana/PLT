#include "attackCharacter.hpp"
#include <iostream>
using namespace engine;

AttackCharacter::AttackCharacter(state::MobileElement& attacker, state::MobileElement& target, state::LevelState& levelState) : attacker(attacker), target(target), levelState(levelState)
{
}


AttackCharacter::~AttackCharacter()
{
}

void AttackCharacter::apply(state::LevelState&) {
	target.setHP(target.getHP() - (attacker.getAttackPt() - target.getDefensePt()));
	
	if (target.getHP() < 0)
		;//detruire l'element
}

