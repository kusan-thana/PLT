#ifndef PathMap_H
#define PathMap_H
#include "element.hpp"
#include "elementGrid.hpp"
#include "pathMapTarget.hpp"

namespace ai {
	
class PathMap {
	
	protected:
		int* weights;
		int width;
		int height;
		
	public:
		PathMap();
		~PathMap();
		int getWidth() const;
		int getHeight() const;
		int getWeight(int x, int y, state::Direction) const;
		int* getWeights() const;
		void setWeight(int x, int y, int w);
		void computeWeights(const state::ElementGrid& grid, state::Element* element);
		void display();
};
}
#endif
