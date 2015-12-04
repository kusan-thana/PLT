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
		bool movePlayed;
		Status status;
		TypeAction action;
		
	public:
		MobileElement();
		bool isStatic() const;
		int getNbStep() const;
		int getNbAction() const;
		bool getTurnPlayed() const;
		void setTurnPlayed(bool turnPlayed);
		void setNbAction(int nbAction);
		virtual bool isPlayerCharacter() const =0;
		void setHP(int HP);
		int getHP() const;
		int getAttackPt() const;
		void setAttackPt(int attackPt);
		int getDefensePt() const;
		void setDefensePt(int defensePt);
		void setMovePlayed(bool movePlayed);
		bool getMovePlayed() const;
		virtual Element* clone() const =0;


};
}
#endif
