#ifndef MobileElement_H
#define MobileElement_H

#include "element.hpp"

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
		
	public:
		MobileElement();
		bool isStatic() const;
		int getNbStep() const;
		int getNbAction() const;
		void setNbAction(int nbAction);
		virtual bool isPlayerCharacter() =0;
};

#endif