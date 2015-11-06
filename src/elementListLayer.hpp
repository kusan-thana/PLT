#ifndef ElementListLayer_H
#define ElementListLayer_H
#include "layer.hpp"
#include "levelStateEvent.hpp"
#include "elementList.hpp"

namespace render {

class ElementListLayer : public Layer {
	
	protected:
		void update(const state::ElementList& elementList, int i);
		
	public:
		virtual void levelStateChanged(const state::LevelStateEvent& e);
};
}
#endif
