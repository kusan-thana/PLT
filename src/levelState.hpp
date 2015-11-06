#ifndef LevelState_H
#define LevelState_H
#include "observable.hpp"
#include "elementGrid.hpp"
#include "elementList.hpp"


namespace state {

class LevelState : public Observable {

	protected:
		state::ElementList characters;
		state::ElementGrid grid;
		
	public:
		LevelState();
		const ElementGrid& getElementGrid() const;
		ElementGrid& getElementGrid();
		const ElementList& getElementList() const;
		ElementList& getElementList();
		void setElementFactory(ElementFactory* factory);
		void loadLevel(const char* file_name);
};
}
#endif



