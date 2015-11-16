#ifndef IHM_H
#define IHM_H

#include "ihmObservable.hpp"
#include "levelState.hpp"
#include "cursor.hpp"

namespace ihm
{ 
	class IHM : public IHMObservable
	{
	protected:
		state::LevelState& levelState;
		Cursor cursor;
		
	public:
		IHM(state::LevelState& levelState);
		~IHM();
		Cursor& getCursor();
		void setCursor(const Cursor& cursor);


	};
}
#endif
