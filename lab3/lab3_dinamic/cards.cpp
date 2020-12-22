#include <iostream>
#include "lab3_din.h"
#include <ctime>

int deck::get_N(){
	return N;
}

/*void deck::isc_dist(){
	delete [] my_deck;
}*/

deck::deck(){
	N = 52;
	my_deck = new card[N];  
	for (int i = 0; i < N; ++i){
		my_deck[i].suit = completion_rand(i, my_deck).suit;
		my_deck[i].rang = completion_rand(i, my_deck).rang;
	}
}

deck::deck(int n){
	N = n;
	my_deck = new card[N];  
	for (int i = 0; i < N; ++i){
		my_deck[i].suit = completion_rand(i, my_deck).suit;
		my_deck[i].rang = completion_rand(i, my_deck).rang;
	}
}

deck::deck(const deck &deck1){
	int i = deck1.N;
	my_deck = new card[i];
	N = i;
	for(int k = 0; k < N; ++k){
		my_deck[k].suit = deck1.my_deck[k].suit;
		my_deck[k].rang = deck1.my_deck[k].rang;
	}
}

deck::~deck(){
	delete [] my_deck;
}

deck deck::operator = (const deck& deck1){
	deck deck2(deck1);
	return deck2;
}

deck& deck::operator ++ (){
	if(check_N(N))
		(N = create_card(my_deck, N));
	return *this;
}

char& deck::operator () (const int& i){
	return (my_deck[i-1].suit);
}

int& deck::operator [] (const int& i){
	return (my_deck[i-1].rang);
}

std::ostream& operator << (std::ostream& out, const deck& d){
	for (int i = 0; i < d.N; ++i){
		out << d.my_deck[i].suit << " " << d.my_deck[i].rang << "\n";
	} 
	return out;
}

std::istream& operator >> (std::istream& in, deck& d){
	//for (int i = 0; i < d.N; ++i){
	try{
		in >> d.my_deck[d.N].suit;
	}catch(std::invalid_argument &err){
		std::cout << "invalid_argument err"<< std::endl;
		d.my_deck[d.N].suit = 'n';
		d.N--;
	}
	try{
		in >> d.my_deck[d.N].rang;
	}catch(std::invalid_argument &err){
		std::cout << "invalid_argument err"<< std::endl;
		d.my_deck[d.N].rang = 0;
	}
	if (check_rs(d.my_deck[d.N].suit, d.my_deck[d.N].rang, d.N, d.my_deck)){
		d.N++;
		return in;
	}else{
		d.my_deck[d.N].rang = 0;
		d.my_deck[d.N].suit = 'n';
	}
	return in;
}

deck& deck::sort_deck(){
	char suit;
	int rang;
	for (int i = 0; i < N; ++i){
		for (int k = 1; k < N; ++k){
			if ((int(my_deck[k].suit) > int(my_deck[k-1].suit)) || ((my_deck[k].rang > my_deck[k-1].rang) && (my_deck[k].suit == my_deck[k-1].suit))){
				suit = my_deck[k].suit;
				rang = my_deck[k].rang;
				my_deck[k].suit = my_deck[k-1].suit;
				my_deck[k].rang = my_deck[k-1].rang;
				my_deck[k-1].rang = rang;
				my_deck[k-1].suit = suit;
			}
		}
	}
	return *this;
}

card* deck::give_suit(char suit){
	int k = 0;
	card *deck_suit = new card[13];
	for(int i = 0; i < N; ++i){
		if (my_deck[i].suit == suit){
			deck_suit[k] = my_deck[i];
			++k;
		}
	}
	for (int i = k; i < 13; ++i){
		deck_suit[i].suit = 'n';
		deck_suit[i].rang = 0;
	}
	return deck_suit;
}
