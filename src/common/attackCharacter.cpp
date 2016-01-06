#include "engine.hpp"
#include <iostream>
using namespace engine;

AttackCharacter::AttackCharacter(state::MobileElement* attacker, state::MobileElement* target) : attacker(attacker), target(target)
{
}


AttackCharacter::~AttackCharacter()
{
}

void AttackCharacter::apply(state::LevelState& levelState) {
	target->setHP(target->getHP() - (attacker->getAttackPt() - target->getDefensePt()));
	attacker->setTurnPlayed(true);

	state::ElementList characters = levelState.getElementList();

	if (target->getHP() <= 0) {
		levelState.getElementList().removeElement(characters.getIdxElement(target));
		levelState.getElementList().notifyObservers(-1);
	}

}

void AttackCharacter::undo(state::LevelState& levelState) {
	
}

