#include "ihm.hpp"

using namespace ihm;

IHM::IHM(state::LevelState& levelState) : levelState(levelState), cursor(*this) {
}
IHM::~IHM(){
}

Cursor& IHM::getCursor()
{
	return cursor;
}

void IHM::setCursor(const Cursor& cursor)
{
	//~ this->cursor = cursor;
}

