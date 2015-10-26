#ifndef StaticElement_H
#define StaticElement_H
#include "element.hpp"

namespace state {

class StaticElement : public Element {
	
	public:
		virtual bool isStatic() const;
		virtual bool isSpace() const =0;

};
}
#endif
