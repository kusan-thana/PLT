#ifndef PathMapTarget_H
#define PathMapTarget_H
#include "element.hpp"

namespace ai {
	
class PathMapTarget {

	public:
		virtual ~PathMapTarget();
		virtual bool isTarget(int x, int y, const state::Element* element) const =0;
};
}
#endif
