#include <iostream>
#include "playerCharacter.hpp"

int main(){
	
	std::cout << "Fantasy World project" << std::endl;
	
	//~ Element e;
	//~ switch(e.getDirection())
	//~ {
		//~ case NONE  : std::cout << "NONE\n";   break;
		//~ case NORTH: std::cout << "NORTH\n"; break;
		//~ case SOUTH : std::cout << "SOUTH\n";  break;
	//~ }
	//MobileElement me;
	//std::cout << me.getNbAction() << std::endl;
	PlayerCharacter p(HERO);
	//std::cout << p.isSelected() << std::endl;
	
	return 0;
}
