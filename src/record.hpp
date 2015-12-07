#pragma once

#include <vector>
#include "actionList.hpp"

namespace engine {

	class Record
	{
	protected:
		std::vector <ActionList*> actions;
	public:
		Record();
		~Record();
		
		void save();
		void loadSave();
	};
}
