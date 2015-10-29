#include "elementGrid.hpp"

#include <iostream>
#include <fstream>

/**
 * ElementGrid_H Class
**/

using namespace state;

ElementGrid::ElementGrid() : width(0), height(0) {
	
	//elements = levelState.getElementList();
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
	char stateLevel[1024];	//Arbitrary size but has to be sufficiently big to contain all characteres of the read file;

	if(file)
	{
		char buf;
		int idx = 0;
		while(file.get(buf)){

			if (buf !='\n'){
				stateLevel[idx] = buf;
//				std::cout << stateLevel[idx];
				++idx;
			}
			if (buf =='\n')
				height += 1;
		}
		width = idx / height;
//		std::cout << std::endl;
		file.close();
	}
	else
		std::cerr << "Failed to open the file!" << std::endl;
}
