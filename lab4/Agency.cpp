#include "Agency.h"

Agency::Agency(std::string Name){
	name = Name;
	obj = NULL;
	next = NULL;
}

const std::string Agency::get_name(){
	return name;
}

/*int Agency::check_type(std::string type){
	if (type == "Tele"){
		Tele* pobg();
		obj = dynamic_cast<Descriptor*>(pobg);	
	}else if(type == "Padio"){
		Radio* pobg();
		obj = dynamic_cast<Descriptor*>(pobg);
	}else if(type == "Print"){
		Print* pobg();
		obj = dynamic_cast<Descriptor*>(pobg);
	}else{
		return 0;
	}
	return 1;
}*/