#include "ruler.hpp"

#include <iostream>
#include <unordered_map>
#include "activateCommand.hpp"
#include "moveCharacter.hpp"

using namespace engine;

/* Suppresion des commandes manuellement à la fin - fonctionnement voulu ? */

Ruler::Ruler(CommandSet& commandSet, state::LevelState& levelState) : commands(commandSet), curr_LevelState(levelState), actions(levelState)
{
	
}

Ruler::~Ruler()
{
		
}

void Ruler::apply(){
	//std::cout << "apply\n";
	
	//~ for (int i = 0; i < commands.size(); i++){
		//~ 
		//~ switch (commands.get(i)->getTypeId()){
			//~ case MAIN:
			//~ 
				//~ break;
			//~ case MODE:
			//~ 
				//~ break;
			//~ case SELECTION:
			//~ 
				//~ break;
			//~ case ACTIVATE:
				//~ //std::cout << dynamic_cast<ActivateCommand*>(commands.get(i))->getDirection(); 
				//~ actions.add(new MoveCharacter(0));
				//~ break;
		//~ }
	//~ }
//~ commands.get(ACTIVATE)->getDirection();
	
	if(commands.size()){
		
		Command* cmd = commands.get(ACTIVATE);
		MoveCharacter* character = new MoveCharacter(0);
		
		switch (((ActivateCommand*)cmd)->getDirection()){
			
			case state::Direction::NORTH:
				character->setDirection(state::Direction::NORTH);
				character->setCoords(-1,0,0);
				actions.add(character);
				break;
			case state::Direction::SOUTH:
				character->setDirection(state::Direction::SOUTH);
				character->setCoords(1,0,0);
				actions.add(character);
				break;
			case state::Direction::EAST:
				character->setDirection(state::Direction::EAST);
				character->setCoords(0,1,0);
				actions.add(character);
				break;
			case state::Direction::WEST:
				character->setDirection(state::Direction::WEST);
				character->setCoords(0,-1,0);
				actions.add(character);
				break;
		}
	}
	std::cout << std::endl;
	actions.apply();
}
