#ifndef Coords_H
#define Coords_H
#include "element.hpp"

namespace ai {
	
class Coords {

	public:
		int x;
		int y;
		int value;
		
		Coords(int x, int y);
		Coords(int x, int y, state::Direction direction);
		Coords(int x, int y, state::Direction direction, int value);
		bool operator<(const Coords& coords) const;
};
}
#endif
