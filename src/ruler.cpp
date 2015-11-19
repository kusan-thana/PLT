#include "ruler.hpp"

#include <iostream>
#include <unordered_map>
#include "command.hpp"
#include "moveCommand.hpp"
#include "moveCharacter.hpp"
#include "loadCommand.hpp"

using namespace engine;
using namespace std;

/* Suppresion des commandes manuellement à la fin - fonctionnement voulu ? */

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


	if (commands.get(MOVE)) {
		cmd = commands.get(MOVE);
		state::Element* perso = ((MoveCommand*)cmd)->getCharacter();
		if (curr_LevelState.getElementGrid().getCell(((MoveCommand*)cmd)->getPositionX(), ((MoveCommand*)cmd)->getPositionY())->getTypeID() == state::SPACE && curr_LevelState.getElementList().getElement(((MoveCommand*)cmd)->getPositionX(), ((MoveCommand*)cmd)->getPositionY()) == 0){
			MoveCharacter* movecharac = new MoveCharacter(perso,((MoveCommand*)cmd)->getPositionX(), ((MoveCommand*)cmd)->getPositionY(), curr_LevelState);
			actions.add(movecharac);
			//~ curr_LevelState.setEpoch(curr_LevelState.getEpoch() + 1);	
		}
	}
	if (commands.get(MAIN)) {
		cmd = commands.get(MAIN);
	
	/* Creer le niveau ici !*/
	}


	//std::cout << std::endl;
	
	actions.apply();

	
}
