#include <iostream>
#include "lab1.h"

void matrix::matrix_start(){
	give_coord();
}

void matrix::give_coord(){
	std::cin >> x >> y;
}

void matrix::create_matrix(){
	m = new int* [x]; 
	m2 = new int* [x];
	int data;
   	for (int i = 0; i < x; i++){
      	m[i] = new int [y];
      	m2[i] = new int [y];
    }
    for (int i = 0; i < x; i++){
      	for (int j = 0; j < y; j++){
      		std::cin >> data;
      		m[i][j] = data;
      		m2[i][j] = data;
      	}
    }
}

void matrix::sorting(){
	int mx[y]; //max and min
	int mn[y];
	int k = 0;
	int t = 0;
	int max;
	int min;
	for (int i = 0; i < x; i++){
		max = m[i][0];
		min = m[i][0];
		for (int j = 0; j < y; j++){
			if (((max < m[i][j]) && (m[i][j] != 0)) || max == 0){
				max = m[i][j];
				k = 0;
				mx[k] = j;
				k++;
			} else if(max == m[i][j]){
				mx[k] = j;
				k++;
			}
			if (((min > m[i][j]) && (m[i][j] != 0)) || min == 0){
				min = m[i][j];
				t = 0;
				mn[t] = j;
				t++;
			} else if(min == m[i][j]){
				mn[t] = j;
				t++;
			}
		}
		if(k >= t){
			for(int j = 0; j < t; j++){
				m[i][mx[j]] = min;
				m[i][mn[j]] = max;
			}
		}else{
			for(int j = 0; j < k; j++){
				m[i][mx[j]] = min;
				m[i][mn[j]] = max;
			}
		}
		k = 0;
		t = 0;
	}
}

void matrix::print_matrix(){

	for (int i = 0; i < x; i++){
      	for (int j = 0; j < y; j++){
      		std::cout <<  m2[i][j] << " ";
      	}
    	std::cout << std::endl;
    }

    std::cout << std::endl;

	for (int i = 0; i < x; i++){
      	for (int j = 0; j < y; j++){
      		std::cout <<  m[i][j] << " ";
      	}
    	std::cout << std::endl;
    }
}