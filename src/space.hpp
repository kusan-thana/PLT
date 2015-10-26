#ifndef Space_H
#define Space_H
#include "staticElement.hpp"

enum SpaceTypeID { GRASS=1, START=2, ENERGY=3 };

namespace state {
	
class Space : public StaticElement {
	
	protected:
		SpaceTypeID IDSpace;
	
	public:
		Space(SpaceTypeID id);
		virtual bool isSpace() const;
		SpaceTypeID getSpaceTypeID() const;
		void setSpaceTypeID(SpaceTypeID id);

};
}
#endif
