#ifndef IHMEvent_H
#define IHMEvent_H
#include "ihm.hpp"

namespace ihm
{
class IHM;	
	
	class IHMEvent
	{

		public:
			IHM& ihm;
			Cursor& cursor;
			int idx;

			IHMEvent(Cursor& cursor, int idx);
			~IHMEvent();
		
	};
}
#endif
