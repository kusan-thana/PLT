#include "ruler.hpp"

#include <iostream>
#include <unordered_map>
#include "moveElement.hpp"
#include "command.hpp"
#include "activerPersonnage.hpp"

using namespace engine;
using namespace std;

/* Suppresion des commandes manuellement à la fin - fonctionnement voulu ? */

Ruler::Ruler(CommandSet& commandSet, state::LevelState& levelState) : commands(commandSet), curr_LevelState(levelState), actions(levelState)
{
	
}

Ruler::~Ruler()
{
		
}

void Ruler::apply(){
	//std::cout << "apply\n";
/*
	state::Element* perso = curr_LevelState.getElementList().getElement(0);
	//~ state::Element* redTile = curr_LevelState.getElementCursors().getElement(0);	/////////////////////

	if (commands.get(ACTIVATE)) {
		Command* cmd = commands.get(ACTIVATE);

		//std::cout << dynamic_cast<ActivateCommand*>(commands.get(i))->getDirection(); 
		//~ MoveElement* moveTile = new MoveElement(curr_LevelState.getElementCursors().getElement(0));		/////////////////

		switch (((ActivateCommand*)cmd)->getDirection()) {
			case state::Direction::NORTH:
				//~ moveTile->setCoords(-1, 0);		////////////
				break;
			case state::Direction::SOUTH:
				//~ moveTile->setCoords(1, 0);		///////////////
				break;
			case state::Direction::EAST:
				//~ moveTile->setCoords(0, 1);		//////////////
				break;
			case state::Direction::WEST:
				//~ moveTile->setCoords(0, -1);		//////////////
				break;
			case state::Direction::NORTHEAST:
				//~ moveTile->setCoords(-1, 1);		//////////////
				break;
			case state::Direction::NORTHWEST:
				//~ moveTile->setCoords(-1, -1);		//////////////
				break;
			case state::Direction::SOUTHEAST:
				//~ moveTile->setCoords(1, 1);		//////////////
				break;
			case state::Direction::SOUTHWEST:
				//~ moveTile->setCoords(1, -1);		//////////////
				break;
		}
		//~ actions.add(moveTile);				//////////////
		//~ if (redTile->getX() == perso->getX() && redTile->getY() == perso->getY() && perso->isActive()) {
			//~ MoveElement* moveChar = new MoveElement(moveTile);
			//~ moveChar->setTile(perso);
			//~ cout << "test" << endl;
			//~ actions.add(moveChar);
			//~ cout << perso->getX() << " " << perso->getY() << endl;
		//~ }
	}

	if (commands.get(SELECTION)) {
		Command* cmd = commands.get(SELECTION);
		state::Element* redTile = curr_LevelState.getElementCursors().getElement(0);
		state::Element* perso = curr_LevelState.getElementList().getElement(0);

		//cout << redTile->getX() << " " << redTile->getY()  << endl;
		//cout << perso->getX() << " " << perso->getY() << endl;

		if (redTile->getX() == perso->getX() && redTile->getY() == perso->getY()){
			ActiverPersonnage* activerPerso = new ActiverPersonnage(perso);
			actions.add(activerPerso);
		}

	}
	//std::cout << std::endl;

	actions.apply();
	*/
}
