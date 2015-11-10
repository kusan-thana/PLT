#ifndef Scene_H
#define Scene_H
#include <vector>
#include "levelStateObserver.hpp"
#include "layer.hpp"
#include "levelStateEvent.hpp"

namespace render {
	
	enum SceneLayer { GRID_LAYER=0, CURSORS_LAYER=1, CHARACTERS_LAYER=2, STATE_LAYER=3 };

	class Scene : public state::LevelStateObserver{
		
		protected:
			int width;
			int height;
			//~ std::vector<std::unique_ptr<Layer> > layers;
			std::vector<Layer*> layers;
			
		public:
			Scene();
			~Scene();
			void setLayer(int idx, Layer* layer);
			virtual void levelStateChanged(const state::LevelStateEvent& e);
	};
}

#endif
