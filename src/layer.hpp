#ifndef Layer_H
#define Layer_H

#include "surface.hpp"
#include "sfmlsurface.hpp"

class Layer {
	
	protected:
		Surface* surface;
		
	public:
		Layer();
		virtual ~Layer();
		void setSurface(Surface* surface);
};

#endif
