#include <iostream>
#include <string>
#include "Descriptor.h"

class Agency{
	private:
		std::string name; 
	public:
		Descriptor *obj;
		Agency * next;
		Agency(std::string);
		const std::string get_name();
		//int check_type(std::string);
};