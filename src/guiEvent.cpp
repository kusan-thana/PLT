#include "guiEvent.hpp"

using namespace gui;

GUIEvent::GUIEvent(GUIElementList& guiElementList, int idx) : gui(guiElementList.getGui()),guiElementList(guiElementList), idx(idx)
{
}


GUIEvent::~GUIEvent()
{
}
