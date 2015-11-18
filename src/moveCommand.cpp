#include "moveCommand.hpp"
#include <iostream>

using namespace engine;

MoveCommand::MoveCommand(int x, int y) : x(x), y(y)
{
	//std::cout << "PositionCommand bien creer ! ";
}


MoveCommand::~MoveCommand()
{
}

CommandTypeId MoveCommand::getTypeId() const {
	return POSITION;
}


int MoveCommand::getPositionX() const
{
	return x;
}
int MoveCommand::getPositionY() const
{
	return y;
}
void MoveCommand::setPosition(int x, int y) {

	this->x = x;
	this->y = y;
}

