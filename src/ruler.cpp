#include "ruler.hpp"

#include <iostream>
#include <unordered_map>
#include "command.hpp"
#include "moveCommand.hpp"
#include "moveCharacter.hpp"
#include "loadCommand.hpp"
#include "mobileElement.hpp"
#include "attackCommand.hpp"
#include "attackCharacter.hpp"
#include "incEpoch.hpp"
#include "endTurnAction.hpp"

using namespace engine;
using namespace std;

/* Suppresion des commandes manuellement � la fin - fonctionnement voulu ? */

Ruler::Ruler(ActionList& actions, CommandSet& commandSet, state::LevelState& levelState) : commands(commandSet), curr_LevelState(levelState), actions(actions)
{
	
}

Ruler::~Ruler()
{
		
}

void Ruler::apply(){
	//std::cout << "apply\n";
	Command* cmd;
	//state::Element* perso = curr_LevelState.getElementList().getElement(0);
	//~ state::Element* redTile = curr_LevelState.getElementCursors().getElement(0);	/////////////////////
	if (commands.get(ATTACK)) {
		cmd = commands.get(ATTACK);
		state::MobileElement* attacker = (state::MobileElement*)(((AttackCommand*)cmd)->getAttacker());
		state::MobileElement* target = (state::MobileElement*)(((AttackCommand*)cmd)->getTarget());
		if (!((state::MobileElement*)((AttackCommand*)cmd)->getAttacker())->getTurnPlayed()) { //Le personnage peut attaquer
			if (attacker->isPlayerCharacter() != target->isPlayerCharacter()) {
				if (abs(attacker->getX() - target->getX()) <= 1 && abs(attacker->getY() - target->getY()) <= 1) {
					AttackCharacter* attackcharac = new AttackCharacter(attacker, target, curr_LevelState);
					actions.add(attackcharac);
					actions.add(new IncEpoch());
				}
			}
		}
	}

	if (commands.get(MOVE)) {
		cmd = commands.get(MOVE);
		state::Element* perso = ((MoveCommand*)cmd)->getCharacter();
		if (curr_LevelState.getElementList().getElement(((MoveCommand*)cmd)->getPositionX(), ((MoveCommand*)cmd)->getPositionY()) == ((MoveCommand*)cmd)->getCharacter()) {
			//std::cout << "BENOIT C'EST LE MEILLEUR" << std::endl;
			EndTurnAction* endTurncharac = new EndTurnAction(perso);
			actions.add(endTurncharac);
			actions.add(new IncEpoch());
		}
		if (!((state::MobileElement*)((MoveCommand*)cmd)->getCharacter())->getMovePlayed()) { //Le personnage peut jouer
			if (curr_LevelState.getElementGrid().getCell(((MoveCommand*)cmd)->getPositionX(), ((MoveCommand*)cmd)->getPositionY())->getTypeId() == state::SPACE && curr_LevelState.getElementList().getElement(((MoveCommand*)cmd)->getPositionX(), ((MoveCommand*)cmd)->getPositionY()) == 0) { //Space non occupe 
				if (abs(((MoveCommand*)cmd)->getPositionX() - ((MoveCommand*)cmd)->getCharacter()->getX()) <= ((state::MobileElement*)((MoveCommand*)cmd)->getCharacter())->getNbStep() && abs(((MoveCommand*)cmd)->getPositionY() - ((MoveCommand*)cmd)->getCharacter()->getY()) <= ((state::MobileElement*)((MoveCommand*)cmd)->getCharacter())->getNbStep()) { //movement < nbStep
					MoveCharacter* movecharac = new MoveCharacter(perso, ((MoveCommand*)cmd)->getPositionX(), ((MoveCommand*)cmd)->getPositionY(), curr_LevelState);
					actions.add(movecharac);
					actions.add(new IncEpoch());
				}
			}
		}
	}

	if (commands.get(MAIN)) {
		cmd = commands.get(MAIN);
		curr_LevelState.loadLevel(((LoadCommand*)cmd)->getFileName());
		curr_LevelState.getElementGrid().notifyObservers(-1, -1);
	}

	//std::cout << std::endl;
	
	actions.apply();

	
}
