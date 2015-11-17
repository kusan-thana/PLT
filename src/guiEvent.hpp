#ifndef GUIEvent_H
#define GUIEvent_H
#include "gui.hpp"

namespace gui
{
class GUI;	
	
	class GUIEvent
	{

		public:
			GUI& GUI;
			Cursor& cursor;
			int idx;

			GUIEvent(Cursor& cursor, int idx);
			~GUIEvent();
		
	};
}
#endif
