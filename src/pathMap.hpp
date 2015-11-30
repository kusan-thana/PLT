#ifndef PathMap_H
#define PathMap_H
#include "levelState.hpp"
#include <queue>
#include <vector>
#include "element.hpp"
#include "pathMapTarget.hpp"
#include "coords.hpp"
#include <vector>

namespace ai {

static const std::vector<state::Direction> directions{state::Direction::NONE, state::Direction::NORTH, state::Direction::SOUTH, state::Direction::EAST, state::Direction::WEST};

class PathMap {

	protected:
		
		const state::LevelState& levelState;
		std::vector<state::Element*> elements;
		int* weights;
		int width;
		int height;
		
	public:
		PathMap(const state::LevelState& levelState);
		~PathMap();
		void clear();
		void addElement(state::Element* element);
		int getWidth() const;
		int getHeight() const;
		int* getWeights() const;
		int getMetadata(int x, int y) const;
		int getMetadata(int x, int y, state::Direction direction) const;
		void setMetadata(int x, int y, int value);
		void setMetadata(int x, int y, int value, state::Direction direction);
		void initMetadata(int defaultValue);
		bool isValid(int x, int y) const;
		bool isValid(int x, int y, state::Direction direction) const;
		int relax (int x, int y, state::Direction direction);
		void dijsktra();
		void display();
};
}
#endif
