#ifndef GUIObservable_H
#define GUIObservable_H

#include <vector>
#include "guiObserver.hpp"

namespace gui
{
class GUIEvent;
	
	class GUIObservable
	{
	protected:
		std::vector<GUIObserver*> observers;

	public:
		GUIObservable();
		~GUIObservable();

		void registerObserver(GUIObserver* o);
		void unregisterObserver(GUIObserver* o);
		void notifyObservers(const GUIEvent& o);

	};
}
#endif
