#include "commandSet.hpp"
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
std::cout << "cmd->getTypeId() in commandSet " << cmd->getTypeId() << std::endl;
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
		case(SELECTION):
		{
			commandList[SELECTION] = cmd;
		}
		break;
		case(ACTIVATE):
		{
			commandList[ACTIVATE] = cmd;	
			//~ std::cout << "cmd->getTypeId() in commandSet " << cmd->getTypeId() << std::endl;
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
