#ifndef GUIMoveRange_H
#define GUIMoveRange_H
#include "guiElementList.hpp"
#include "element.hpp"

namespace gui {

class GUIMoveRange : public GUIElementList {
	
	protected:
		state::Element* element;
		int length;

	public:
		GUIMoveRange(GUI& gui);
		int getLength() const;
		void setLength(int length);
		void setElement(state::Element* element);
		void computeRange();
};
}
#endif
