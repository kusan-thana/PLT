#ifndef LevelState_H
#define LevelState_H
#include "observable.hpp"
#include "elementGrid.hpp"
#include "elementList.hpp"


namespace state {
	enum TurnToPlay { PLAYER = 0, OPPONENT = 1};

class LevelState : public Observable {

	protected:
		state::ElementList characters;
		state::ElementGrid grid;
		int epoch;
		TurnToPlay turnToPlay;
		
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
		TurnToPlay getTurnToPlay() const;
		void setTurnToPlay(TurnToPlay turnToPlay);
		LevelState* clone() const;
		void copy(const LevelState& levelState);
};
}
#endif



