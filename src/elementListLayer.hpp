#ifndef ElementListLayer_H
#define ElementListLayer_H
#include "layer.hpp"
#include "levelStateEvent.hpp"

namespace render {

class ElementListLayer : public Layer {
	
	public:
		virtual void levelStateChanged(const state::LevelStateEvent& e);
};
}
#endif
