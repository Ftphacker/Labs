#include <iostream>

class Ast{
	private:
		int R;
	public:
		Ast(int n);
		bool input_r(int pobg); //rty execept 
		float len_part_arc(int t);
		float len_all_arc();
		float roc(int t); //radius of curvature
		float area();
		float return_x(int t);
		float return_y(int t);
		double xfy(int x);
};

int dialog();

int give_t(); 

bool check_n(int);

int check_input_r();