#ifndef GUIObserver_H
#define GUIObserver_H

namespace gui
{
class GUIEvent;

	class GUIObserver
	{
		public:
			~GUIObserver() {};
			virtual void guiChanged(const GUIEvent& e) =0;
			
	};
}
#endif
