#ifndef GUITile_H
#define GUITile_H
#include "guiElement.hpp"

namespace gui {

class GUITile : public GUIElement {
	
	public:
		GUITile(int x, int y, GUITypeId guiTypeId);
		virtual GUITypeId getGuiTypeId() const;
};
}
#endif
