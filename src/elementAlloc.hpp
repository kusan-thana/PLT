#ifndef ElementAlloc_H
#define ElementAlloc_H
#include "aElementAlloc.hpp"

namespace state {

template <class E, typename ID>
class ElementAlloc : public AElementAlloc {
	
	protected:
		ID id;

	public:
		ElementAlloc(ID id);
		virtual Element* newInstance();

};

template <class E, typename ID>
ElementAlloc<E,ID>::ElementAlloc(ID id) : id(id) {
}

template <class E, typename ID>
Element* ElementAlloc<E,ID>::newInstance(){

	switch(id){
		case HERO:
			return (new E(HERO));
		case BRUTE:
			return (new E(BRUTE));
		//Need to be completed for all elements...
	}
}

}
#endif
