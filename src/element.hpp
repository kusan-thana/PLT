#ifndef Element_H
#define Element_H

enum TypeID {SPACE=1, OBSTACLE=2, HERO=3, BRUTE=4, HEALER=5, WIZARD=6, MINION=7, BOSS=8 };

namespace state {
	enum Direction { NONE = 1, NORTH = 2, SOUTH = 3, EAST = 3, WEST = 4 }; //SOUTH = EAST???

class Element {
	
	protected:
		int x;
		int y;
		bool active;
		TypeID IDElement;
		state::Direction orientation;
		
	public:
		Element();
		virtual ~Element();
		int getX() const;
		int getY() const;
		TypeID getTypeID() const;
		state::Direction getDirection() const;
		void setX(int x);
		void setY(int y);
		void setDirection(state::Direction orientation);
		bool isActive() const;
		virtual bool isStatic() const =0;
};
}
#endif
