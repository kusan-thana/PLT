#ifndef AElementAlloc_H
#define AElementAlloc_H
#include "element.hpp"

namespace state {

class AElementAlloc {

	public:
		virtual ~AElementAlloc();
		virtual Element* newInstance() =0; 
};
}
#endif



