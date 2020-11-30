#include <iostream>
#include "lab2.h"

#define def_r 1

int main(){
	int pobg;
	Ast astroid(def_r);
	int t;
	if (astroid.input_r(1)){
		return 0;
	}
	while (pobg != 0){
		t = give_t();
		pobg = dialog();
		switch (pobg){
			case 1: { 
				std::cout << astroid.len_part_arc(t) << std::endl; break; 
			}
			case 2: { std::cout << astroid.len_all_arc() << std::endl; break; }
			case 3: { std::cout << astroid.roc(t) << std::endl; break; }
			case 4: { std::cout << astroid.area() << std::endl; break; }
			case 5: { std::cout << astroid.return_x(t) << "\n" << astroid.return_y(t) << std::endl ; break; }
			case 6: { std::cout << astroid.xfy(t) << std::endl; break; }
		}
	}
}