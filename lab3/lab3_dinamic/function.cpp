#include <iostream>
#include "lab3_din.h"

bool check_rs(char suit, int rang, int N, card *my_deck){
	bool value = false;
	for (int i = 0; i < N; ++i){
		if ((my_deck[i].suit == suit) && (my_deck[i].rang == rang)){
			value = true;
		}
		if (value == true){
			break;
		}
	}
	if (!value && (rang > 1 && rang < 15) && (suit == 'p' || suit == 'h' || suit == 'b' || suit == 'g')){
		return true;
	}else{
		std::cout<< "incorrect rang or suit\n";
	}
	return false;
}

char rand_suit(){
	int i = rand() % 4;
	switch(i){
		case 0 : return 'h';//hearts
		case 1 : return 'b';//booby
		case 2 : return 'p';//peaks
		case 3 : return 'g';//guilts vini
	}
	return 0;
}

card completion_rand(int n, card *my_deck){
	bool value = true;
	card true_card;
	int rang;
	char suit;
	//static int k;
	srand(time(0));
	while (value){
		value = false;
		rang = 2 + rand() % 13;
		suit = rand_suit();
			//std::cout << suit << " " << rang << "\n";
		for (int i = 0; i < n; ++i){
			if ((my_deck[i].suit == suit) && (my_deck[i].rang == rang)){
				value = true;
			}
			if (value == true){
				break;
			}
			//std::cout << i << '\n';
		}
	}
	//std::cout << k << "\n";
	//k++;
	true_card.rang = rang;
	true_card.suit = suit;
	//std::cout << suit << " " << rang << "\n";
	return true_card;
}

int create_card(card *my_deck, int N){
	//my_deck[N].rang = completion_rand(N, my_deck)->rang;
	N++;
	return N;
}

int check_N(int N){
	return((N < 52)? 1 : 0);
}

int dialog(){
	int i;
	std::cout << "input command : \n"; // 1,2,3,4,5
	std::cout << "0.exit\n1.add rand card\n2.receive suid of card\n3.receive rang of card\n4.sort cards\n5.select a subgroup\n6.print all deck\n7.input new card\n"; //select a subgroup of cards of the specified suit from a group of cards.
	try{
		std::cin >> i;
	}catch(std::invalid_argument &err){
		std::cout << "invalid_argument err"<< std::endl;
		//throw 1;
		return 0;
	}
	return i;
}

int dialog(int g){
	int i;
	std::cout << "input command : \n"; // 1,2,3,4,5
	std::cout << "0.exit\n1.add rand card\n2.receive suid of card\n3.receive rang of card\n4.sort cards\n5.select a subgroup\n6.print all deck\n7.input new card\n8.create new deck\n"; //select a subgroup of cards of the specified suit from a group of cards.
	try{
		std::cin >> i;
	}catch(std::invalid_argument &err){
		std::cout << "invalid_argument err"<< std::endl;
		//throw 1;
		return 0;
	}
	return i;
}

deck add_card(deck my_deck){
	if (my_deck.get_N() < 52)
		++my_deck;
	else
		std::cout<<"deck has bin comleted\n";
	return my_deck;
}

int receive_suid(deck my_deck){
	int i;
	std::cout << "input num card\n";
	try{
		std::cin >> i;
	}catch(std::invalid_argument &err){
		std::cout << "invalid_argument err"<< std::endl;
		return 0;
	}
	if (i > 52 || i < 1)
		std::cout << "incorrect number of card\n";
	else
		std::cout << my_deck[i]<<std::endl; 
	return 0;

}

int receive_rang(deck my_deck){
	int i;
	std::cout << "input num card\n";
	try{
		std::cin >> i;
	}catch(std::invalid_argument &err){
		std::cout << "invalid_argument err"<< std::endl;
		return 0;
	}
	if (i > 52 || i < 1)
		std::cout << "incorrect number of card\n";
	else
		std::cout << my_deck(i)<< std::endl;
	return 0;
}

deck sort(deck my_deck){
	my_deck = my_deck.sort_deck();
	return my_deck;
}

int select(deck my_deck){
	char i;
	card *deck_suit;
	std::cout<<"input suit\n";
	try{
		std::cin >> i;
	}catch(std::invalid_argument &err){
		std::cout << "invalid_argument err"<< std::endl;
		return 0;
	}
	deck_suit = my_deck.give_suit(i);
	for(int k = 0; k < 13; ++k){
		if(deck_suit[k].suit != 'n'){
			std::cout << deck_suit[k].suit <<deck_suit[k].rang << std::endl;
		}
	}
	delete [] deck_suit;
	return 0;
}

void print_my_deck(deck my_deck){
	//my_deck.print_deck();
	std::cout << my_deck;
}

deck input_card(deck my_deck){
	if (check_N(my_deck.get_N())){
		std::cin>>my_deck;
	}else{
		std::cout<<"deck is comleted\n";
	}
	return my_deck;
	
}

deck executor(deck my_deck, int i){
	switch(i){
		case 1 : {my_deck = add_card(my_deck); break;}
		case 2 : {receive_suid(my_deck); break;}
		case 3 : {receive_rang(my_deck); break;}
		case 4 : {my_deck = sort(my_deck); break;}
		case 5 : {select(my_deck); break;}
		case 6 : {print_my_deck(my_deck); break;}
		case 7 : {my_deck = input_card(my_deck); break;}
	}
	return my_deck;
}

deck create_deck(deck my_deck){
	deck my_deck2(my_deck);
	std::cout << my_deck2;
	return my_deck2;
}

deck executor(deck my_deck, int i, int pobg){
	switch(i){
		case 1 : {my_deck = add_card(my_deck); break;}
		case 2 : {receive_suid(my_deck); break;}
		case 3 : {receive_rang(my_deck); break;}
		case 4 : {my_deck = sort(my_deck); break;}
		case 5 : {select(my_deck); break;}
		case 6 : {print_my_deck(my_deck); break;}
		case 7 : {my_deck = input_card(my_deck); break;}
		case 8 : {deck my_deck2 = create_deck(my_deck); break;}
		//case 9 : {my_deck = input_card(my_deck); break;}
	}
	return my_deck;
}

void prog1(){
	deck deck1(40);
	int i = 1;
	while (i != 0){
		i = dialog();
		if(i < 0 || i > 7) 
			std::cout<<"input other number\n";
		else
			deck1 = executor(deck1, i);
	}
}

void prog2(){
	deck deck1;
	int i = 1;
	while (i != 0){
		i = dialog(0);
		if(i < 0 || i > 9) 
			std::cout<<"input other number\n";
		else
			deck1 = executor(deck1, i, 0);
	}
	//deck1.isc_dist();
}