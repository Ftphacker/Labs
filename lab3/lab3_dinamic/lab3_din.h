#include <iostream>

struct card{
	char suit;
	int rang;
};

class deck{
	private:
		int N;
		card *my_deck;
	public:
		deck();
		deck(int);
		deck(const deck&);
		~deck();
		deck& operator ++ ();                             
		char& operator () (const int&);
		int& operator [] (const int&);
		deck operator = (const deck&);
		friend std::ostream& operator<<(std::ostream &out, const deck &);
		friend std::istream& operator>>(std::istream &in, deck &);
		deck& sort_deck();
		card* give_suit(char);
		int get_N();
};

int dialog();

int dialog(int);

void prog1();

void prog2();

char rand_suit();

card completion_rand(int, card*);

int create_card(card*, int);

int check_N(int N);

bool check_rs(char, int, int, card*);