#include "sfmlSurface.hpp"

#include <iostream>
/**
 * SFMLSurface Class
**/
SFMLSurface::SFMLSurface() : widthSprite(32), heigthSprite(32){
}
void SFMLSurface::clear(){
	
	vertices.clear();
}
void SFMLSurface::loadTexture(const char* tileset){

	if (!this->tileset.loadFromFile(tileset))
		std::cout << "Texture Error.." << std::endl;
}
void SFMLSurface::setSpriteCount(int n){

	this->vertices.setPrimitiveType(sf::Quads);
    this->vertices.resize(n * 4);
}
/** Position du sprite dans la fenêtre.
 *  Le sprite est défini par : 
 *  - Quatres sommets définis à partir de l'indice i
 *  - La position du coin haut-gauche du sprite dans la fenêtre à la position (x,y) 
 **/
 void SFMLSurface::setSpriteLocation(int i, int x, int y){
	
	sf::Vertex* quad = &vertices[i * 4];
	
	quad[0].position = sf::Vector2f(x, y);
	quad[1].position = sf::Vector2f(x + widthSprite, y);		//Value 32 fixed !!
	quad[2].position = sf::Vector2f(x + widthSprite, y + heigthSprite);
	quad[3].position = sf::Vector2f(x, y + heigthSprite);
}
/** Position du sprite dans la texture.
 * 	Coordonnées des quatres sommets sur la texture 
 **/ 
void SFMLSurface::setSpriteTexture(int i, const render::StaticTile* staticTile){

	sf::Vertex* quad = &vertices[i * 4];
	
	int x = staticTile->getX();
	int y = staticTile->getY();
	int width = staticTile->getWidth();
	int height = staticTile->getHeight();
	
	quad[0].texCoords = sf::Vector2f(x, y);
	quad[1].texCoords = sf::Vector2f(x + width, y);
	quad[2].texCoords = sf::Vector2f(x + width, y + height);
	quad[3].texCoords = sf::Vector2f(x, y + height);
}
void SFMLSurface::draw(sf::RenderTarget& target, sf::RenderStates states) const{

	// on applique la transformation
	states.transform *= getTransform();

	// on applique la texture du tileset
	states.texture = &(this->tileset);

	// et on dessine enfin le tableau de vertex
	target.draw(this->vertices, states);
}
void SFMLSurface::setSpriteWidth(int spriteWidth){
	
	this->widthSprite = widthSprite;
}
void SFMLSurface::setSpriteHeight(int spriteHeight){
	
	this->heigthSprite = heigthSprite;
}
SFMLSurface& SFMLSurface::getSfmlSurface(){

	return *this;
}

