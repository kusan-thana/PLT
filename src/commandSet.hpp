#pragma once

#include <unordered_map>
#include "command.hpp"

namespace engine {
	
	class CommandSet{
		
	protected:
		std::unordered_map<int, Command*> commandList;
		
	public:
		CommandSet();
		~CommandSet();
		int size() const;
		void set(Command *cmd);
		Command* get(int category) const;
		void clear();
	};
}
