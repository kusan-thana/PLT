#include "guiEvent.hpp"

using namespace gui;

GUIEvent::GUIEvent(Cursor& cursor, int idx) : GUI(cursor.getGUI()), cursor(cursor), idx(idx)
{
}


GUIEvent::~GUIEvent()
{
}
