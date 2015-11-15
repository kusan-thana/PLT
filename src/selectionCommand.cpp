#include "selectionCommand.hpp"

using namespace engine;

SelectionCommand::SelectionCommand(bool select) : selected(select)
{
}


SelectionCommand::~SelectionCommand()
{
}


CommandTypeId SelectionCommand::getTypeId() const {
	return SELECTION;
}


bool SelectionCommand::getSelectedValue() const {
	return selected;
}
