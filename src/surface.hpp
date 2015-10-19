#ifndef Surface_H
#define Surface_H
#include <SFML/Graphics.hpp>

class Surface {
	
	protected:
		sf::Texture	texture;

	public:
		void loadTexture(const char* image_file);
};

#endif
