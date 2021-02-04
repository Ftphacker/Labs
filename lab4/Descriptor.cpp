#include <iostream>
#include <string>
#include "Descriptor.h"

Descriptor::Descriptor(int _license, std::string _type, std::string _profile, std::string _place){
	license = _license;
	type = _type;
	profile = _profile;
	place = _place;
}

Descriptor::Descriptor(){
	license = 0;
	type = "";
	profile = "";
	place = "";
}

int Descriptor::print_all_info(){
	std::cout << license << "\n" << type << "\n" << profile << "\n" << place << "\n"; 
	return 0;
}

std::string Descriptor::get_type(){
	return type;
}

std::string Descriptor::get_place(){
	return place;
}

int Descriptor::get_license(){
	return license;
}

std::string Descriptor::get_profile(){
	return profile;
}

Descriptor* Descriptor::get_this(){
	return this;
}