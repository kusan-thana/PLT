#ifndef GUITile_H
#define GUITile_H
#include "guiElement.hpp"

namespace gui {

class GUITile : public GUIElement {
	
	public:
		GUITile(int x, int y);
		virtual GUITypeId getGuiTypeId() const;
};
}
#endif