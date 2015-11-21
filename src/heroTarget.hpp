#ifndef HeroTarget_H
#define HeroTarget_H
#include "pathMapTarget.hpp"
#include "element.hpp"

namespace ai {
	
class HeroTarget : public PathMapTarget {
	
	protected:
		state::Element* hero;
		
	public:
		HeroTarget(state::Element* element);
		virtual bool isTarget(int x, int y, const state::Element* e) const;
		//~ const state::Element* getElement() const;
};
}
#endif
