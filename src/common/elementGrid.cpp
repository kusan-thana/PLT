#include "state.hpp"

#include <iostream>
#include <fstream>

/**
 * ElementGrid Class
**/

using namespace state;

ElementGrid::ElementGrid(LevelState& levelState) : ElementList(levelState), width(5), height(5) {
}
int ElementGrid::getWidth() const{
		

	return width;
}
int ElementGrid::getHeight() const{
		
	return height;
}
Element* ElementGrid::getCell(int i, int j) const{

	return elements[i*width + j];
}
void ElementGrid::load(const char* file_name){
	
	std::ifstream file(file_name, std::ios::in);
	char stateLevel[1024]={0};	//Arbitrary size but has to be sufficiently big to contain all characteres of the read file;
	this->width = 0;
	this->height = 0;
	clear();
	//~ this->elements.clear();
	
	if(file)
	{
		char buf;
		int idx = 0;
		while(file.get(buf)){

			if (buf !='\n'){
				stateLevel[idx] = buf;
				++idx;
			}
			if (buf =='\n')
				height += 1;
		}
		width = idx / height;
		file.close();
	}
	else
		std::cerr << "Failed to open the file!" << std::endl;
	
	
	for (unsigned int i = 0; i < height; ++i)
	{
		for (unsigned int j = 0; j < width; ++j)
		{
			switch(stateLevel[j+i*width]){
				case('0'):
				{
					Element* grassElem = factory->newInstance('0');	//Instanciation d'un nouvel élément
					grassElem->setX(i);
					grassElem->setY(j);
					setElement(j+i*width, grassElem);			//Ajout du (j+i*width)ième élément dans la liste d'élément
				}
				break;
				case('1'):
				{
					Element* waterElem = factory->newInstance('1');
					waterElem->setX(i);
					waterElem->setY(j);
					setElement(j+i*width, waterElem);
				}
				break;
				case('2'):
				{
					Element* treeElem = factory->newInstance('2');
					treeElem->setX(i);
					treeElem->setY(j);
					setElement(j+i*width, treeElem);
				}
				break;
				case('3'):
				{
					Element* firElem = factory->newInstance('3');
					firElem->setX(i);
					firElem->setY(j);
					setElement(j+i*width, firElem);
				}
				break;
			}
		}
	}
}
/** i => height ; j => width **/
void ElementGrid::notifyObservers(int i, int j) {
	
	LevelListEvent levelListEvent(*this,i*(this->width)+j);
	Observable::notifyObservers(levelListEvent);
}
ElementGrid* ElementGrid::clone() const{
	
	ElementGrid* clone = new ElementGrid(levelState);
	
	clone->factory = this->factory;
	for(int i=0; i<size(); i++){
		
		clone->elements.push_back(this->elements[i]->clone());
	}
	clone->width = this->width;
	clone->height = this->height;
	
	return clone;
}
void ElementGrid::copy(const ElementGrid& grid){
	
	this->factory = grid.factory;

	this->elements.clear();
	for(int i=0; i<grid.size(); i++){
		
		this->elements.push_back(grid.elements[i]->clone());
	}
	this->width = width;
	this->height = height;
}
