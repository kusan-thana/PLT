#ifndef IHMObserver_H
#define IHMObserver_H

namespace ihm
{
class IHMEvent;

	class IHMObserver
	{
		public:
			virtual void ihmChanged(const IHMEvent& e) =0;
	};
}
#endif
