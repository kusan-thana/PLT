#ifndef PlayerCharacter_H
#define PlayerCharacter_H

#include "mobileElement.hpp"

namespace state {



class PlayerCharacter : public MobileElement{
	
	protected:
		int mana;
	
	public:
		PlayerCharacter(TypeId IdElement);
		virtual bool isPlayerCharacter() const;
		Status getStatus() const;
		virtual Element* clone() const; 
};
}
#endif
