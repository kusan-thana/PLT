#ifndef GUIMoveRange_H
#define GUIMoveRange_H
#include "guiElementList.hpp"
#include "element.hpp"
namespace gui {

class GUIMoveRange : public GUIElementList {
	
	protected:
		int length;

	public:
		GUIMoveRange(GUI& gui, int length, state::Element* element);
		int getLength() const;
		void setLength(int length);
};
}
#endif
