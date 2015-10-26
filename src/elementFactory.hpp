#ifndef ElementFactory_H
#define ElementFactory_H
#include <map>

#include "aElementAlloc.hpp"
#include "element.hpp"

namespace state {

class ElementFactory {

	protected:
		std::map<char,state::AElementAlloc*> list;

	public:
		Element* const newInstance(char id);
		void registerType(char id, AElementAlloc* a);
		
};
}
#endif



