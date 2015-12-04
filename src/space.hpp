#ifndef Space_H
#define Space_H
#include "staticElement.hpp"

enum SpaceTypeID { GRASS=1, START=2, ENERGY=3, RED=4, YELLOW=5, GREEN=6 };

namespace state {
	
class Space : public StaticElement {
	
	protected:
		SpaceTypeID IDSpace;
	
	public:
		Space(SpaceTypeID id);
		virtual bool isSpace() const;
		SpaceTypeID getSpaceTypeID() const;
		void setSpaceTypeID(SpaceTypeID id);
		virtual Element* clone() const;

};
}
#endif
