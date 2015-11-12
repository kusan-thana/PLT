#include "Ruler.hpp"

#include <iostream>
#include <unordered_map>
#include "ActivateCommand.hpp"
using namespace engine;

/* Suppresion des commandes manuellement à la fin - fonctionnement voulu ? */

Ruler::Ruler(CommandSet& commandSet, const state::LevelState& levelState)
{

	for (auto it = commandSet.commandList.begin(); it != commandSet.commandList.end(); ++it) {
		//std::cout << commandSet.size();
		
		switch (it->second->getCommandTypeId()){
			case engine::MAIN:

				break;
			case engine::MODE:
				break;
			case engine::SELECTION:
				break;
			case engine::ACTIVATE:
				std::cout << dynamic_cast<ActivateCommand*>(it->second)->getDirection();
				break;
		}

		commandSet.commandList.erase(it);
	}

		
}


Ruler::~Ruler()
{
}
