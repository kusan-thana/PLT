#include "moveCommand.hpp"
#include <iostream>

using namespace engine;

MoveCommand::MoveCommand(int x, int y, state::Element* character) : x(x), y(y), character(character)
{
	//std::cout << "PositionCommand bien creer ! ";
}


MoveCommand::~MoveCommand()
{
}

CommandTypeId MoveCommand::getTypeId() const {
	return MOVE;
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

state::Element * engine::MoveCommand::getCharacter()
{
	return character;
}

