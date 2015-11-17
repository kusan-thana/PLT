#include "guiEvent.hpp"

using namespace gui;

GUIEvent::GUIEvent(Cursor& cursor, int idx) : gui(cursor.getGUI()), cursor(cursor), idx(idx)
{
}


GUIEvent::~GUIEvent()
{
}
