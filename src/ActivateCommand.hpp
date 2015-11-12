#pragma once

#include "command.hpp"
#include "levelState.hpp"

namespace engine {
	class ActivateCommand : public Command
	{
	protected:
		state::Direction direction;

	public:
		ActivateCommand(state::Direction dir);
		~ActivateCommand();
		CommandTypeId ActivateCommand::getCommandTypeId() const;
		state::Direction ActivateCommand::getDirection() const;

	};
}
