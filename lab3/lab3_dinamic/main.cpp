#include <iostream>
#include "lab3_din.h"

int main(){
	int version;
	std::cout << "print version programm" << std::endl; 
	try{
		std::cin >> version;
	}catch(std::invalid_argument &err){
		std::cout << "invalid_argument err"<< std::endl;
		return 0;
	}
	if(version != 1 && version != 2){
		std::cout << "invalid_argument err"<< std::endl;
	}
	switch (version) {
		case 1: { prog1(); break; }
		case 2: { prog2(); break; }
	} 
}