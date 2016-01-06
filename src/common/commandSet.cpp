#include "engine.hpp"
#include <iostream>
using namespace engine;

CommandSet::CommandSet() {
}
CommandSet::~CommandSet() {
}
int CommandSet::size() const {

	return  commandList.size();
}
void CommandSet::set(Command *cmd) {

//~ commandList[commandList.size()] = cmd;

	switch(cmd->getTypeId())
	{
		case(MAIN):
		{
			commandList[MAIN] = cmd;
		}
		break;
		case(MODE):
		{
			commandList[MODE] = cmd;
		}
		break;
		case(MOVE):
		{
			commandList[MOVE] = cmd;
		}
		break;
		case(ATTACK) :
		{
			commandList[ATTACK] = cmd;
		}
		break;
	}
}
Command* CommandSet::get(int category) const{
	auto search = commandList.find(category);
	if (search != commandList.end())
		return commandList.find(category)->second;
	else
		return 0;
}
void CommandSet::clear(){

	commandList.clear();
}
