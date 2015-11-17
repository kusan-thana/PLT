#include "ruler.hpp"

#include <iostream>
#include <unordered_map>
#include "moveElement.hpp"
#include "command.hpp"
#include "positionCommand.hpp"
#include "moveCharacter.hpp"

using namespace engine;
using namespace std;

/* Suppresion des commandes manuellement � la fin - fonctionnement voulu ? */

Ruler::Ruler(CommandSet& commandSet, state::LevelState& levelState) : commands(commandSet), curr_LevelState(levelState), actions(levelState)
{
	
}

Ruler::~Ruler()
{
		
}

void Ruler::apply(){
	//std::cout << "apply\n";

	state::Element* perso = curr_LevelState.getElementList().getElement(0);
	//~ state::Element* redTile = curr_LevelState.getElementCursors().getElement(0);	/////////////////////


	if (commands.get(POSITION)) {
		Command* cmd = commands.get(POSITION);
		state::Element* perso = curr_LevelState.getElementList().getElement(0);
		MoveCharacter* movecharac = new MoveCharacter(perso,((PositionCommand*)cmd)->getPositionX(), ((PositionCommand*)cmd)->getPositionY(), curr_LevelState);
		actions.add(movecharac);
	}

	//std::cout << std::endl;
	
	actions.apply();
	
}
