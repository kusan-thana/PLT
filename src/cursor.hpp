#ifndef Cursor_H
#define Cursor_H
#include "guiElement.hpp"
#include "levelState.hpp"

namespace gui {
	
class GUI;

	class Cursor : public GUIElement {
		
		protected:
			state::Element* character;
			state::LevelState& levelState;

		public:
			Cursor(state::LevelState& levelState);
			~Cursor();
			virtual void setX(int x);
			virtual void setY(int y);
			virtual void setActive(bool active);
			void setcharacter(state::Element* character);
			state::Element* getcharacter();
			GUITypeId getGuiTypeId() const;

	};
}
#endif
