#include "positionCommand.hpp"
#include <iostream>

using namespace engine;

PositionCommand::PositionCommand(int x, int y) : x(x), y(y)
{
	//std::cout << "PositionCommand bien creer ! ";
}


PositionCommand::~PositionCommand()
{
}

CommandTypeId PositionCommand::getTypeId() const {
	return POSITION;
}


int PositionCommand::getPositionX() const
{
	return x;
}
int PositionCommand::getPositionY() const
{
	return y;
}
void PositionCommand::setPosition(int x, int y) {

	this->x = x;
	this->y = y;
}

