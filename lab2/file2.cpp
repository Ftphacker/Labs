#include <iostream>
#include "lab2.h"
#include <stdexcept>
#include <exception>

int give_t(){ 
	int t = 0;
	std::cout<<"input t :: ";
	try{
		std::cin>>t;
	}catch(std::invalid_argument &err){
		std::cout << "invalid_argument err"<< std::endl;
		return 0;
	}
	return t;
}

int dialog(){ 
	int pobg;
	std::cout<< "input command :\n 0 :: exit\n 1 :: len_part_astroid\n 2 :: len_all_astroid\n 3 :: radius of curvature\n 4 :: areas astroid\n 5 :: x and y from t\n 6 :: y from x\n";
	try{
		std::cin>>pobg;
	}catch(std::invalid_argument &err){
		std::cout << "invalid_argument err"<< std::endl;
		return 0;
	}
	return pobg;
}

bool check_n(int n){
	if (n < 0){
		std::cout<< "Error line"<< std::endl;
		return false;
	}else{
		return true;
	}
}

int check_input_r(){
	int pobg = 0;
	try{
		std::cin>>pobg;
	}catch(std::invalid_argument &err){
		return 0;
	}
	return pobg;
}