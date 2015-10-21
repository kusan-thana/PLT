#include "client.hpp"

/**
 * Client Class
**/
void Client::run(){
	
	while(acquireControls())
		{
			updateDisplay();
		}
}
