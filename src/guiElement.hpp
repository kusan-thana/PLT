#ifndef GUIElement_H
#define GUIElement_H

namespace gui {
	
	enum GUITypeId { CURSOR = 1, MOVE_RANGE = 2 };

class GUIElement {
	
	protected:
		int x;
		int y;
		bool active;
		GUITypeId guiTypeId;
		
	public:
		GUIElement();
		virtual ~GUIElement();
		int getX() const;
		int getY() const;
		bool getActive() const;
		virtual GUITypeId getGuiTypeId() const =0;
		virtual void setX(int x);
		virtual void setY(int y);
		virtual void setActive(bool active);
};
}
#endif
