#pragma once

#include "command.hpp"
#include "levelState.hpp"

namespace engine {
	class MoveCommand : public Command
	{
	protected:
		int x;
		int y;

	public:
		MoveCommand(int x, int y);
		~MoveCommand();
		virtual CommandTypeId getTypeId() const;
		int getPositionX() const;
		int getPositionY() const;
		void setPosition(int x, int y);
	};
}
