#include <iostream>

struct card {
	char suit;  // hearts, booby, peaks, guilts
	int rang; // 1,2,3 ...
};

class deck {
	private:
		int N;
		card my_deck[52];
	public :
		deck();
		deck(int);
		int get_N();
		deck& operator ++ ();
		char& operator () (const int&);
		int& operator [] (const int&);
		friend std::ostream& operator<<(std::ostream &out, const deck &);
		friend std::istream& operator>>(std::istream &in, deck &);
		deck& sort_deck();
		card* give_suit(char);
};

int dialog();

void prog1();

char rand_suit();

card completion_rand(int, card*);

int create_card(card*, int);

int check_N(int N);

bool check_rs(char, int, int, card*);






