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
		state::ElementList cursors;
		
	public:
		LevelState();
		void setElementFactory(ElementFactory* factory);
		const ElementGrid& getElementGrid() const;
		ElementGrid& getElementGrid();
		const ElementList& getElementList() const;
		ElementList& getElementList();
		const ElementList& getElementCursors() const;
		ElementList& getElementCursors();
		void loadLevel(const char* file_name);
};
}
#endif



