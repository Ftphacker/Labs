#include <iostream>
#include <string>
#include "Print.h"

Print::Print(int _period, int _tiraj, int license, std::string type, std::string profile, std::string place) : Descriptor(license, type, profile, place){
	period = _period;
	tiraj = _tiraj;
}

Print::Print() : Descriptor(){
	period = 0;
	tiraj = 0;
}

int Print::get_period(){
	return period;
}

int Print::get_tiraj(){
	return tiraj;
}

int Print::change_period(int new_period){
	period = new_period;
	return 0;
}
int Print::change_tiraj(int new_tiraj){
	tiraj = new_tiraj;
	return 0;
}
int Print::print_all_info(){
	std::cout << profile << "\n" << license << "\n" << place << "\n" << period << "\n" << tiraj << "\n" << type <<"\n"; 
	return 0;
}

