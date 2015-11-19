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
		int epoch;
		
	public:
		LevelState();
		void setElementFactory(ElementFactory* factory);	
		const ElementGrid& getElementGrid() const;
		ElementGrid& getElementGrid();
		const ElementList& getElementList() const;
		ElementList& getElementList();
		void loadLevel(const char* file_name);
		int getEpoch();
		void setEpoch(int epoch);
};
}
#endif



