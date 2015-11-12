#pragma once

#include <unordered_map>
#include "Command.hpp"

namespace engine {
	class CommandSet{
	protected:
		
	public:
		std::unordered_map<int, Command*> commandList; //A deplacer dans protected...
		CommandSet();
		~CommandSet();
		int CommandSet::size() const;
		void CommandSet::set(Command *cmd);
	};
}
