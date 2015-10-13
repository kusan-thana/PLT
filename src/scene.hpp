#ifndef Scene_H
#define Scene_H
#include <vector>
#include "layer.hpp"

class Scene {
	
	protected:
		std::vector<Layer*> layers;
		
	public:
		Scene();
		~Scene();
		void setLayer(Layer* layer);
};

#endif
