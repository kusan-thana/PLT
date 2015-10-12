#ifndef PlayerCharacter_H
#define PlayerCharacter_H

#include "mobileElement.hpp"

enum TypeAction{PUNCH, SWORDSTRIKE, HAMMERSTRIKE, HEAL, REINFORCEMENT, FIREBALL};
enum Status {NORMAL=1, SUPER=2, DEAD=3};

class PlayerCharacter : public MobileElement{
	
	protected:
		int mana;
		bool selected;
		Status status;
		TypeAction action;
		
	public:
		PlayerCharacter(TypeID IDElement);
		virtual bool isPlayerCharacter() const;
		void doAction(MobileElement& target, TypeAction action);
		Status getStatus() const;
		bool isSelected();
		
};

#endif
