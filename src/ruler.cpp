#include "ruler.hpp"

#include <iostream>
#include <unordered_map>
#include "activateCommand.hpp"
using namespace engine;

/* Suppresion des commandes manuellement à la fin - fonctionnement voulu ? */

Ruler::Ruler(CommandSet& commandSet, const state::LevelState& levelState) : commands(commandSet), curr_LevelState(levelState)
{
	if ((int)commandSet.size() != 0)
		std::cout << "test"; 
		
}


Ruler::~Ruler()
{
		
}

void Ruler::apply(){
	std::cout << "apply\n";
	
	for (int i = 0; i < commands.size(); i++){
		
		switch (commands.get(i)->getTypeId()){
			case engine::MAIN:
				break;
			case engine::MODE:
				break;
			case engine::SELECTION:
				break;
			case engine::ACTIVATE:			
				std::cout << dynamic_cast<ActivateCommand*>(commands.get(i))->getDirection();
				break;
		}
	}
}
