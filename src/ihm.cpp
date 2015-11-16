#include "ihm.hpp"

using namespace ihm;


IHM::IHM() : cursor (0,0){
}


IHM::~IHM(){
}

Cursor& IHM::getCursor()
{
	return cursor;
}

void IHM::setCursor(Cursor&)
{
	this->cursor = cursor;
}

