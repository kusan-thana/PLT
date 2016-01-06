#include "engine.hpp"

using namespace engine;

ModeCommand::ModeCommand(EngineMode mode):mode(mode)
{
}


ModeCommand::~ModeCommand()
{
}

CommandTypeId ModeCommand::getTypeId() const {
	return MODE;
}
EngineMode ModeCommand::getMode() const {
	return mode;
}