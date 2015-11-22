#ifndef PlayerCharacter_H
#define PlayerCharacter_H

#include "mobileElement.hpp"

namespace state {



class PlayerCharacter : public MobileElement{
	
	protected:
		int mana;
	
	public:
		PlayerCharacter(TypeID IDElement);
		virtual bool isPlayerCharacter() const;
		void doAction(MobileElement& target, TypeAction action);
		Status getStatus() const;
};
}
#endif
