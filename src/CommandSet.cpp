#include "CommandSet.hpp"

using namespace engine;

CommandSet::CommandSet() {
}


CommandSet::~CommandSet() {
}

int CommandSet::size() const {
	return  (int) commandList.size();
}

void CommandSet::set(Command *cmd) {
	commandList[commandList.size()] = cmd;
}