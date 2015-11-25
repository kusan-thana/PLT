#ifndef GUIElementList_H
#define GUIElementList_H
#include "guiObservable.hpp"
#include "guiElement.hpp"
#include <vector>

namespace gui {

// forward declared dependencies
class GUI;

class GUIElementList : public GUIObservable {
	
	protected:
		GUI& gui;
		std::vector<GUIElement*> guiElements;

	public:
		GUIElementList(GUI& gui);
		GUI& getGui();
		int size() const;
		GUIElement* getGuiElement(int i) const;
		GUIElement* getGuiElement(int x, int y) const;
		void setGuiElement(int i, GUIElement* guiElement);
		void notifyObservers(int i);
		void update();
};
}
#endif
