#pragma once
#include "command.hpp"
#include "engine.hpp"

namespace engine{

class ModeCommand :public Command
{
protected: 
	EngineMode mode;
public:
	ModeCommand(EngineMode mode);
	~ModeCommand();
	CommandTypeId getTypeId() const;
	EngineMode getMode() const;
};

}

