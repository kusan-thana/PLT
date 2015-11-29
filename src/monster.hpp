#ifndef Monster_H
#define Monster_H

#include "mobileElement.hpp"

namespace state {

class Monster : public MobileElement{
	
	public:
		Monster(TypeId IdElement);
		virtual bool isPlayerCharacter() const;
		Status getStatus() const;
};
}
#endif
