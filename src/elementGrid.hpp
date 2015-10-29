#ifndef ElementGrid_H
#define ElementGrid_H
#include "elementList.hpp"
//#include "levelState.hpp"

namespace state {

class ElementGrid : public ElementList{

	protected:
		int width;
		int height;
		
	public:
		ElementGrid();
		int getWidth() const;
		int getHeight() const;
		Element* getCell(int i, int j) const;
		void load(const char* file_name);
};
}
#endif



