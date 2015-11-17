#ifndef Cursor_H
#define Cursor_H
#include "guiObservable.hpp"
#include "levelState.hpp"

namespace gui {
	
class GUI;

	class Cursor : public GUIObservable {
		
		protected:
			GUI& gui;
			int x;
			int y;
			bool active;
			state::LevelState& levelState;

		public:
			Cursor(GUI& gui, state::LevelState& levelState);
			~Cursor();
			int getX();
			int getY();
			void setX(int x);
			void setY(int y);
			GUI& getGUI();
			void notifyObservers(int i);
			void setActive(bool active);
			bool getActive();
	};
}
#endif
