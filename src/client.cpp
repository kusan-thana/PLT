#include "client.hpp"

/**
 * Client Class
**/

using namespace client;

Client::Client() : scene(1024,512){
}
void Client::init(){
	

}
void Client::run(){
	
	this->init();

    
	while(acquireControls()){
			updateDisplay();
	}	
}
