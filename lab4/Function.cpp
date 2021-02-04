#include "Radio.h"



int dialog1(){
	int res;
	std::cout << " 1.add new agency\n 2.find agency\n 3.delate agency\n 4.show all agency\n 0.exit\n";
	std::cin >> res;
	if ((res > 4) || (res < 1)){
		return 0;
	}
	return res;
}

int dialog2(){
	int res;
	std::cout << " 1.print info\n 2.print type\n 3.print place\n 4.print license\n 5.print profile\n 0.NO\n";
	std::cin >> res;
	if ((res > 5) || (res < 1)){
		return 0;
	}
	return res;
}

int add(Agency * &table){
	std::string name, type, profile, place;
	int license;
	std::cout << "print name new agency :: ";
	std::cin >> name;
	std::cout << "print type new agency :: ";
	std::cin >> type;
	std::cout << "print profile new agency :: ";
	std::cin >> profile;
	std::cout << "print place new agency :: ";
	std::cin >> place;
	std::cout << "print lizensy new agency :: ";
	std::cin >> license;
	if(type == "Tele"){
		int channel;
		std::cout << "print channel new agency :: ";
		std::cin >> channel;
		//int _channel) : Descriptor(license, type, profile, place
		Tele *new_tele = new Tele{channel, license, type, profile, place};
		//new_tele.init_type(type);
		Agency *new_agency = new Agency{name};
		new_agency->obj = new_tele;
		//Descriptor* tab_dest = dynamic_cast<Descriptor*>(new_tele);	
		//new_agency->obj = new_tele;
		std::cout << new_agency->obj->print_all_info() << std::endl;
		//new_agency->obj = tab_tele;
		//std::cout << tab_dest->channel << std::endl;
		if(table == NULL){
			table = new_agency;
			new_agency->next = NULL;
		}else{
			new_agency->next = table;
			table = new_agency;
		}
	}else if(type == "Radio"){
		int frequency;
		range obj;
		std::cout << "print frequency new agency :: ";
		std::cin >> frequency;
		std::cout << "print range new agency :: ";
		std::cin >> obj.x;
		std::cin >> obj.y;
		Radio *new_radio = new Radio{frequency, obj, license, type, profile, place};
		//new_radio.init_type(type);
		Agency *new_agency = new Agency{name};
		new_agency->obj = dynamic_cast<Descriptor*>(new_radio);	
		new_agency->obj = new_radio;
		if(table == NULL){
			table = new_agency;
			new_agency->next = NULL;
		}else{
			new_agency->next = table;
			table = new_agency;
		}
	}else if(type == "Print"){
		int tiraj;
		int period;
		std::cout << "print tiraj new agency :: ";
		std::cin >> tiraj;
		std::cout << "print period new agency :: ";
		std::cin >> period;
		Print *new_print = new Print{tiraj, period, license, type, profile, place};
		//new_print.init_type(type);
		Agency *new_agency = new Agency{name};
		new_agency->obj = dynamic_cast<Descriptor*>(new_print);	
		new_agency->obj = new_print;
		//std::cout << new_agency->obj->print_all_info() << std::endl;
		if(table == NULL){
			table = new_agency;
			new_agency->next = NULL;
		}else{
			new_agency->next = table;
			table = new_agency;
		}
	}else{
		return 0;
	}
	//std::cout << table->obj->type;
	return 0;
}

int show(Agency * table){
	Agency *pobg = table;
	while (pobg!= NULL){
		std::cout << "aaa\n";
		std::cout << pobg->obj->print_all_info() << "\n";
		std::cout<<"\n\n\n";
		pobg = pobg->next;
	}
	return 0;
}

int find(Agency * table){
	std::string name;
	std::cout<<"print name :: ";
	std::cin>>name;
	Agency * pobg = table;
	while (pobg != NULL){
		if (pobg->get_name() == name){
			pobg->obj->print_all_info();
			int com = dialog2();
			while (com != 0){
				switch(com){
					case 1:{pobg->obj->print_all_info();break;}
					case 2:{pobg->obj->get_type();break;}
					case 3:{pobg->obj->get_place();break;}
					case 5:{pobg->obj->get_profile();break;}
					case 4:{pobg->obj->get_license();break;}
				}
			}
			break;
		}else{
			pobg = pobg->next;
		}
		if(pobg == NULL){
			std::cout << "NO element";
		}
	}
	return 0;
}

int delete_(Agency * &table){
	std::string name;
	std::cout<<"print name :: ";
	std::cin>>name;
	Agency * pobg = table;
	Agency * pobg2 = table;
	while (table != NULL){
		if (table->get_name() == name){
			pobg2->next = table->next;
			break;
		}else{
			pobg2 = table;
			table = table->next;
		}
	}
	if((table->next == NULL) && (table->get_name() == name)){
		table = NULL;
		return 0;
	}
	table = pobg;

	return 0;
}

int exe(int res, Agency* &table){
	switch(res){
		case 1:{add(table);break;}
		case 2:{find(table);break;}
		case 3:{delete_(table);break;}
		case 4:{show(table);break;}
	}
	return res;
}

int prog(){
	int res = 1;
	Agency *table = NULL;
	while (res != 0){
		res = dialog1();
		if (res == 0)break;
		std::cout<<table<<"\n";
		res = exe(res, table);
		std::cout<<table<<"\n";
	}
	//table = exe(res, table);
	return 0;
}

int main(){
	prog();
	return 0;
}