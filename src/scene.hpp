#ifndef Scene_H
#define Scene_H
#include <vector>
#include "layer.hpp"

class Scene {
	
	protected:
		int width;
		int height;
		std::vector<Layer*> layers;
		
	public:
		Scene();
		Scene(int width, int height);
		~Scene();
		void setLayer(Layer* layer);
};

#endif
