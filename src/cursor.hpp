#ifndef Cursor_H
#define Cursor_H
#include "ihmObservable.hpp"

namespace ihm{
	
class IHM;

	class Cursor : public IHMObservable {
		
		protected:
			IHM& ihm;
			int x;
			int y;

		public:
			Cursor(IHM& ihm);
			~Cursor();
			int getX();
			int getY();
			void setX(int x);
			void setY(int y);
			IHM& getIhm();
			void notifyObservers(int i);
	};
}
#endif
