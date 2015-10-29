#ifndef LevelState_H
#define LevelState_H
#include "elementList.hpp"
#include "elementGrid.hpp"

namespace state {

class LevelState {

	protected:
		ElementList elementList;
		ElementGrid grid;
		
	public:
		ElementList& getElementList();
		void loadLevel(const char* file_name);
};
}
#endif



