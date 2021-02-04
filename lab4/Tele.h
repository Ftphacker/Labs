#include "Agency.h"

class Tele: public Descriptor{
	public:
		Tele(int _channel, int license, std::string type, std::string profile, std::string place);
		Tele();
		virtual int print_all_info();
		virtual int get_channel();
	private:
		int channel;
};