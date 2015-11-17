#pragma once

#include "command.hpp"
#include "levelState.hpp"

namespace engine {
	class PositionCommand : public Command
	{
	protected:
		int x;
		int y;

	public:
		PositionCommand(int x, int y);
		~PositionCommand();
		virtual CommandTypeId getTypeId() const;
		int getPositionX() const;
		int getPositionY() const;
		void setPosition(int x, int y);


	};
}
