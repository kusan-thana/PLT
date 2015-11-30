#include "attackCharacter.hpp"
#include <iostream>
using namespace engine;

AttackCharacter::AttackCharacter(state::MobileElement* attacker, state::MobileElement* target, state::LevelState& levelState) : attacker(attacker), target(target), levelState(levelState)
{
}


AttackCharacter::~AttackCharacter()
{
}

void AttackCharacter::apply(state::LevelState&) {
	target->setHP(target->getHP() - (attacker->getAttackPt() - target->getDefensePt()));
	
	state::ElementList characters = levelState.getElementList();

	if (((state::MobileElement*)target)->getHP() <= 0) {
		levelState.getElementList().removeElement(characters.getIdxElement(target));
		levelState.getElementList().notifyObservers(-1);
	}
		
//		for (int i = 0; i<characters.size(); i++) {

//		state::Element* curr_element = characters.getElement(i);
//	if (((state::MobileElement*)curr_element)->getHP() <= 0) {
//		levelState.getElementList().removeElement(curr_element);
//		levelState.getElementList().notifyObservers(-1);
//	}

	//}
	//~ for(int i=0; i< characters.size(); i++)
		//~ if((state::MobileElement*)characters.getElement(i) == target)
			//~ break;
	
	//~ if (target.getHP() < 0){
			//~ characters.getElements().erase (characters.getElements().begin()+characters.getIdxElement(&target));
			//~ std::cout << "size " << characters.size() << std::endl;
	//~ }
}

