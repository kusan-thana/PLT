#pragma once

#include "cursor.hpp"
#include "ihmObservable.hpp"

namespace ihm
{ 
	class IHM : public IHMObservable
	{
	protected:
		Cursor cursor;
	public:
		IHM();
		~IHM();
		Cursor& getCursor();
		void setCursor(Cursor&);


	};
}
