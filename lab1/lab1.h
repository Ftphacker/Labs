#include <iostream>

class matrix{
	private:
		int x;
		int y;
		int **m;
		int **m2;
	public:
		void matrix_start();

		int give_coord();

		int create_matrix();

		void sorting();

		void print_matrix();
};