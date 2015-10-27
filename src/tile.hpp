#ifndef Tile_H
#define Tile_H

namespace render {

class Tile {
	
	public:
		virtual ~Tile();
		virtual bool isAnimated() const =0; 

};
}
#endif



