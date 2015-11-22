#ifndef MobileElement_H
#define MobileElement_H

#include "element.hpp"

namespace state {

enum TypeAction{PUNCH, SWORDSTRIKE, HAMMERSTRIKE, HEAL, REINFORCEMENT, FIREBALL, BITE, POISON, SCRATCH};
enum Status {NORMAL=1, SUPER=2, DEAD=3};

class MobileElement : public Element{
	
	protected:
		int speed;
		int HP;
		int attackPt;
		int defensePt;
		int nbAction;
		int nbStep;
		int level;
		int experience;
		int position;
		bool turnPlayed;
		bool selected;
		Status status;
		TypeAction action;
		
	public:
		MobileElement();
		bool isStatic() const;
		int getNbStep() const;
		int getNbAction() const;
		void setNbAction(int nbAction);
		virtual bool isPlayerCharacter() const =0;
		bool isSelected();
};
}
#endif
