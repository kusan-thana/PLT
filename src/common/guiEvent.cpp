#include "gui.hpp"

using namespace gui;

GUIEvent::GUIEvent(GUIElementList& guiElementList, int idx) : gui(guiElementList.getGui()), levelState(guiElementList.getGui().getLevelState()), guiElementList(guiElementList), idx(idx)
{
}


GUIEvent::~GUIEvent()
{
}
