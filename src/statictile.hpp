#ifndef StaticTile_H
#define StaticTile_H
#include "tile.hpp"

class StaticTile : public Tile{
	
	protected:
		int x;
		int y;
		int width;
		int height;

	public:
		StaticTile();
		virtual bool isAnimated() const;
		int getX() const;
		int getY() const;
		int getWidth() const;
		int getHeight() const;
		void setX(int x);
		void setY(int y);
		void setWidth(int width);
		void setHeight(int height);

};

#endif



