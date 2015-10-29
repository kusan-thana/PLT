#ifndef ElementList_H
#define ElementList_H
#include <vector>
#include "elementFactory.hpp"
#include "element.hpp"

namespace state {

class ElementList {
	
	protected:
		state::ElementFactory* factory;
		std::vector<state::Element*> elements;

	public:
		int const size();
		state::Element* getElement(int i);
		void setElementFactory(state::ElementFactory* factory);
		void setElement(int i, state::Element* element);

};
}
#endif
