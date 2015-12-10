
#include <iostream>
#include <unordered_map>
#include "engine.hpp"


using namespace engine;
using namespace std;


Ruler::Ruler(ActionList& actions, CommandSet& commandSet, state::LevelState& levelState) : commands(commandSet), curr_LevelState(levelState), actions(actions)
{
	
}

Ruler::~Ruler()
{
		
}

void Ruler::apply(){
	Command* cmd;

	actions.clear();

	//state::Element* perso = curr_LevelState.getElementList().getElement(0);
	//~ state::Element* redTile = curr_LevelState.getElementCursors().getElement(0);	/////////////////////
	if (commands.get(ATTACK)) {
		cmd = commands.get(ATTACK);
		state::MobileElement* attacker = (state::MobileElement*)(((AttackCommand*)cmd)->getAttacker());
		state::MobileElement* target = (state::MobileElement*)(((AttackCommand*)cmd)->getTarget());
		if (!((state::MobileElement*)((AttackCommand*)cmd)->getAttacker())->getTurnPlayed()) { //Le personnage peut attaquer
			if (attacker->isPlayerCharacter() != target->isPlayerCharacter()) {
				if (abs(attacker->getX() - target->getX()) <= 1 && abs(attacker->getY() - target->getY()) <= 1) {
					AttackCharacter* attackcharac = new AttackCharacter(attacker, target);
					actions.add(attackcharac);
					actions.add(new IncEpoch());
				}
			}
		}
	}

	if (commands.get(MOVE)) {
		MoveCommand* cmd = (MoveCommand*)commands.get(MOVE);
		state::Element* perso = cmd->getCharacter();
		if (curr_LevelState.getElementList().getElement(cmd->getPositionX(), cmd->getPositionY()) == cmd->getCharacter()) {
			EndTurnAction* endTurncharac = new EndTurnAction(perso);
			actions.add(endTurncharac);
			actions.add(new IncEpoch());
		}
		if (!((state::MobileElement*)cmd->getCharacter())->getMovePlayed()) { //Le personnage peut jouer
			if (curr_LevelState.getElementGrid().getCell(cmd->getPositionX(), cmd->getPositionY())->getTypeID() == state::SPACE && curr_LevelState.getElementList().getElement(cmd->getPositionX(), cmd->getPositionY()) == 0) { //Space non occupe 
				if (abs(cmd->getPositionX() - cmd->getCharacter()->getX()) <= ((state::MobileElement*)cmd->getCharacter())->getNbStep() && abs(cmd->getPositionY() - cmd->getCharacter()->getY()) <= ((state::MobileElement*)cmd->getCharacter())->getNbStep()) { //movement < nbStep
					MoveCharacter* movecharac = new MoveCharacter(perso, cmd->getPositionX(), cmd->getPositionY(), curr_LevelState);
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

	
	actions.apply();

	
}
