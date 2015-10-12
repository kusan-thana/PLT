#include "surface.hpp"

#include <iostream>
/**
 * Surface Class
**/

void Surface::loadTexture(const char* image_file){
	
	if (!this->texture.loadFromFile(image_file))
	{
		std::cout << "Error Texture loading.." << std::endl;
	}
}
