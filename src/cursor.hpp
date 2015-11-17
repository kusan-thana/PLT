#ifndef Cursor_H
#define Cursor_H
#include "GUIObservable.hpp"

namespace gui {
	
class GUI;

	class Cursor : public GUIObservable {
		
		protected:
			GUI& gui;
			int x;
			int y;

		public:
			Cursor(GUI& gui);
			~Cursor();
			int getX();
			int getY();
			void setX(int x);
			void setY(int y);
			GUI& getGUI();
			void notifyObservers(int i);
	};
}
#endif
