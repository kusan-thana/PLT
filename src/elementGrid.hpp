#ifndef ElementGrid_H
#define ElementGrid_H

#include "elementList.hpp"
#include "element.hpp"

namespace state {

// forward declared dependencies
class LevelState;

class ElementGrid : public ElementList{

	protected:
		int width;
		int height;

	public:
		ElementGrid(state::LevelState& levelState);
		int getWidth() const;
		int getHeight() const;
		Element* getCell(int i, int j) const;
		void load(const char* file_name);
};
}
#endif



