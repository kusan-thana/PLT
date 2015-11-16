#ifndef IHMObservable_H
#define IHMObservable_H

#include <vector>
#include "ihmObserver.hpp"

namespace ihm
{
class IHMEvent;
	
	class IHMObservable
	{
	protected:
		std::vector<IHMObserver*> observers;

	public:
		IHMObservable();
		~IHMObservable();

		void registerObserver(IHMObserver* o);
		void unregisterObserver(IHMObserver* o);
		void notifyObservers(const IHMEvent& o);

	};
}
#endif
