#ifndef StaticTile_H
#define StaticTile_H
#include <SFML/Graphics.hpp>
#include "tile.hpp"

class StaticTile : public Tile{
	
	protected:
		int x;
		int y;
		int width;
		int height;
		sf::VertexArray vertices;

	public:
		StaticTile();
		bool isAnimated() const;
		void setX(int x);
		void setY(int y);
		void setWidth(int width);
		void setHeight(int height);

};

#endif



