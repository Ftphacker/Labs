#include <iostream>
#include <string>
#include "Tele.h"

Tele::Tele(int _channel, int license, std::string type, std::string profile, std::string place) : Descriptor(license, type, profile, place){
	channel = _channel;
}

Tele::Tele() : Descriptor(){
	channel = 0;
}

int Tele::get_channel(){
	return channel;
}

int Tele::print_all_info(){
	std::cout << profile << "\n" << license << "\n" << place << "\n" << channel << "\n" << type<<"\n"; 
	return 0;
}