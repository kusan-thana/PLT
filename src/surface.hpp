#ifndef Surface_H
#define Surface_H


class Surface {
	
	public:
		virtual void loadTexture(const char* image_file) =0;
		virtual void setSpriteLocation(int i, const StaticTile* texture) =0; 
};
a
#endif
