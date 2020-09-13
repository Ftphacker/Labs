#include <iostream>
#include "lab1.h"

int main(){

	matrix k;
	k.matrix_start();
	if (!k.create_matrix()){
		std::cout << "Incorrect input data \n";
		return 0;
	}
	k.sorting();
	k.print_matrix();
	//k.print_matrix();
	return 0;
}