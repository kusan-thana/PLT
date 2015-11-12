#include "activateCommand.hpp"
#include <iostream>

using namespace engine;

ActivateCommand::ActivateCommand(state::Direction dir) : direction(dir)
{
	//std::cout << "ActivateCommand bien creer ! ";
}


ActivateCommand::~ActivateCommand()
{
}

CommandTypeId ActivateCommand::getTypeId() const{
	return ACTIVATE;
}


state::Direction ActivateCommand::getDirection() const {
	return direction;
}
