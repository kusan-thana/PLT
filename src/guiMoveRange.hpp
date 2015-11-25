#ifndef GUIMoveRange_H
#define GUIMoveRange_H
#include "guiElementList.hpp"
#include "element.hpp"

namespace gui {

class gui;

class GUIMoveRange : public GUIElementList {
	
	protected:
		state::Element* element;

	public:
		GUIMoveRange(GUI& gui);
		void setElement(state::Element* element);
		void computeRange();
};
}
#endif
