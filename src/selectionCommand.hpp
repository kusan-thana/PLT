#pragma once

#include "command.hpp"

namespace engine {

	class SelectionCommand : public Command
	{
	protected:
		bool selected;

	public:

		SelectionCommand(bool selected);
		~SelectionCommand();
		bool getSelectedValue() const;
		CommandTypeId getTypeId() const;


	};

}