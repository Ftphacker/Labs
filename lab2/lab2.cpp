#include <iostream>
#include "lab2.h"
#include <cmath>
#include <stdexcept>
#include <exception>

#define def_r 1

Ast::Ast(int n){
	R = n;
	if(!check_n(n)){
		R = 1;
	}
}

float Ast::len_part_arc(int t){
	float l;
	l = (3.0/2.0)*R*pow((sin(t)),2);
	return l;
}

float Ast::len_all_arc(){
	float l;
	l = 6*R;
	return l;
}

float Ast::roc(int t){
	float roc;
	roc = fabs((3.0/2.0)*R*(sin(2*t)));
	return roc;
}

float Ast::area(){
	float s;
	s = (3.0/2.0)*M_PI*R;
	return s;
}

double Ast::xfy(int x){                                         ////////////////////////////&&&&&&&&&&&&&&&&&&&77??????????????????????????????????????//
	double y;
	y = pow((R),(2.0/3.0)) - pow((x),(2.0/3.0));
	return y; 
}

bool Ast::input_r(int pobg){
	std::cout<<"input r :: ";
	pobg = check_input_r();
	if (pobg != 0){
		R = pobg;
		return true;
	}else{
		std::cout << "invalid_argument err"<< std::endl;
		return false; 
	}
}

float Ast::return_x(int t){
	float x = R*pow((cos(t)),3);
	return x;
}

float Ast::return_y(int t){
	float y = R*pow((sin(t)),3);
	return y;
}