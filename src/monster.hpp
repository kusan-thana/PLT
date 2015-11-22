#ifndef Monster_H
#define Monster_H

#include "mobileElement.hpp"

namespace state {

class Monster : public MobileElement{
	
	public:
		Monster(TypeID IDElement);
		virtual bool isPlayerCharacter() const;
		void doAction(MobileElement& target, TypeAction action);
		Status getStatus() const;
};
}
#endif
