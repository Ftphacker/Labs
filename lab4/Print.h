#include "Tele.h"

class Print: public Descriptor{
	public:
		Print(int, int,  int license, std::string type, std::string profile, std::string place);
		Print();
		virtual int get_period();
		virtual int get_tiraj();
		virtual int change_period(int new_period);
		virtual int change_tiraj(int new_tiraj);
		virtual int print_all_info();
	private:
		int period;
		int tiraj;
};