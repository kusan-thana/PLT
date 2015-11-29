#ifndef Element_H
#define Element_H

namespace state {
	enum Direction { NONE = 1, NORTH = 2, SOUTH = 3, EAST = 4, WEST = 5, NORTHEAST = 6, NORTHWEST = 7, SOUTHEAST = 8, SOUTHWEST = 9}; //SOUTH = EAST???
	enum TypeId { SPACE = 1, OBSTACLE = 2, HERO = 3, BRUTE = 4, HEALER = 5, WIZARD = 6, MINION = 7, BOSS = 8 };

class Element {
	
	protected:
		int x;
		int y;
		bool active;
		TypeId IdElement;
		state::Direction orientation;
		
	public:
		Element();
		virtual ~Element();
		int getX() const;
		int getY() const;
		TypeId getTypeId() const;
		bool equals(const Element& other) const;
		state::Direction getDirection() const;
		void setX(int x);
		void setY(int y);
		void setActive(bool active);
		void setDirection(state::Direction orientation);
		bool isActive() const;
		virtual bool isStatic() const =0;
};
}
#endif
