#include "Print.h"

struct range{
	int x;
	int y;
};

class Radio: public Descriptor{
	public:
		Radio(int _frequency, range _obj, int license, std::string type, std::string profile, std::string place);
		Radio();
		virtual range get_obj();
		virtual int get_frequency();
		virtual range chage_obj(range _obj);
		virtual int chage_frequency(int _frequency);
		virtual int print_all_info();
	private:
		int frequency;
		range obj;
};