#ifndef GUIEvent_H
#define GUIEvent_H
#include "gui.hpp"
#include "guiElementList.hpp"

namespace gui
{
class GUI;	
	
	class GUIEvent
	{

		public:
			GUI& gui;
			state::LevelState& levelState;
			GUIElementList& guiElementList;
			int idx;

			GUIEvent(GUIElementList& guiElementList, int idx);
			~GUIEvent();
		
	};
}
#endif
