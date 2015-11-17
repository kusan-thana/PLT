#ifndef GUI_H
#define GUI_H

#include "guiObservable.hpp"
#include "levelState.hpp"
#include "cursor.hpp"

namespace gui
{ 
	class GUI : public GUIObservable
	{
	protected:
		state::LevelState& levelState;
		Cursor cursor;
		
	public:
		GUI(state::LevelState& levelState);
		~GUI();
		Cursor& getCursor();
		void setCursor(const Cursor& cursor);


	};
}
#endif
