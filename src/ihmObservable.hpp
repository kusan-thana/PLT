#pragma once

#include <vector>
#include "ihmObserver.hpp"
#include "ihmEvent.hpp"

namespace ihm
{
	class IHMObservable
	{
	protected:
		std::vector<IHMObserver*> observers;

	public:
		IHMObservable();
		~IHMObservable();

		void registerObserver(IHMObserver* o) const;
		void unregisterObserver(IHMObserver* o) const;
		void notifyObserver(const IHMEvent& o) const;

	};
}
