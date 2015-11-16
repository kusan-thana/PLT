#include "ihmEvent.hpp"

using namespace ihm;

IHMEvent::IHMEvent(Cursor& cursor, int idx) : ihm(cursor.getIhm()), cursor(cursor), idx(idx)
{
}


IHMEvent::~IHMEvent()
{
}
