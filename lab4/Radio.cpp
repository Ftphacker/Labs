#include "Radio.h"

Radio::Radio(int _frequency, range _obj, int license, std::string type, std::string profile, std::string place) : Descriptor(license, type, profile, place){
	frequency = _frequency;
	obj = _obj;
}

Radio::Radio() : Descriptor(){
	frequency = 0;
	obj.x = 0;
	obj.y = 0;
}

range Radio::get_obj(){
	return obj;
}

int Radio::get_frequency(){
	return frequency;
}
range Radio::chage_obj(range _obj){
	obj.x = _obj.x;
	obj.y = _obj.y;
	return obj;
}
int Radio::chage_frequency(int _frequency){
	frequency = _frequency;
	return 0;
}
int Radio::print_all_info(){
	std::cout << profile << "\n" << license << "\n" << place << "\n" << obj.x << obj.y << "\n" << frequency << "\n" << type <<"\n";
	return 0;
}