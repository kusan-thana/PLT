#ifndef ElementList_H
#define ElementList_H

#include "elementFactory.hpp"
#include "element.hpp"

#include <vector>

namespace state {

// forward declared dependencies
class LevelState;

class ElementList {
	
	protected:
		state::LevelState& levelState;
		state::ElementFactory* factory;
		std::vector<state::Element*> elements;

	public:
		ElementList(state::LevelState& levelState);
		const LevelState& getLevelState() const;
		int size() const;
		state::Element* getElement(int i) const;
		void setElementFactory(state::ElementFactory* factory);
		void setElement(int i, state::Element* element);

};
}
#endif
