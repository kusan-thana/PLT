#ifndef Scene_H
#define Scene_H
#include <vector>
#include "levelStateObserver.hpp"
#include "layer.hpp"
#include "levelStateEvent.hpp"

namespace render {

	class Scene : public state::LevelStateObserver{
		
		protected:
			int width;
			int height;
		public:
			std::vector<Layer*> layers;
			
		public:
			Scene();
			Scene(int width, int height);
			~Scene();
			void setLayer(Layer* layer);
			virtual void levelStateChanged(const state::LevelStateEvent& e);
	};
}

#endif
