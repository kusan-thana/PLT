#include "sfmlclient.hpp"

/**
 * Client SFMLClass
**/
SFMLClient::SFMLClient() : window(sf::VideoMode(1024, 512), "Fantasy World!") {
}
void SFMLClient::init(){
	
	
	sfmlSurfaces.push_back(new SFMLSurface());
		
	sfmlSurfaces[0]->loadTexture("../res/images/dungeon.gif");
	sfmlSurfaces[0]->setSpriteCount(512);
	

	
	TileSet tileSet;
	StaticTile tree(160,128,32,32);
	tileSet.setStaticTile(tree);
	StaticTile water(160,160,32,32);
	tileSet.setStaticTile(water);
	StaticTile grass(0,160,32,32);
	tileSet.setStaticTile(grass);
	StaticTile fir(224,128,32,32);
	tileSet.setStaticTile(fir);
	
	
	
	
	Layer layer;
	layer.setSurface(sfmlSurfaces[0]);
	layer.setTileSet(&tileSet);
	
	scene.setLayer(&layer);
	
	
    int width = 32;
    int height = 16;
    
    
    const int etat[] = {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };
    
	for (unsigned int i = 0; i < width; ++i)
	{
            for (unsigned int j = 0; j < height; ++j)
			{
				switch(etat[i+j*width]){
					case(0):
						sfmlSurfaces[0]->setSpriteTexture(i+j*width, &tree);
					break;
					case(1):
						sfmlSurfaces[0]->setSpriteTexture(i+j*width, &water);
					break;
					case(2):
						sfmlSurfaces[0]->setSpriteTexture(i+j*width, &grass);
					break;
					case(3):
						sfmlSurfaces[0]->setSpriteTexture(i+j*width, &fir);
					break;
				}
				sfmlSurfaces[0]->setSpriteLocation(i+j*width,i*32,j*32);	
			}
	}
}
bool SFMLClient::acquireControls(){
	
	sf::Event event;
	
	while (this->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		this->window.close();
	}
	
	return this->window.isOpen();
}
void SFMLClient::updateDisplay(){

	this->window.clear();
	this->window.draw(*sfmlSurfaces[0]);
	this->window.display();
}
