#include <iostream>
#include <string>

class Descriptor{
	public:
		Descriptor(int _license, std::string _type, std::string _profile, std::string _place);
		Descriptor();
		virtual int print_all_info();
		std::string get_type();
		std::string get_place();
		int get_license();
		std::string get_profile();
		Descriptor * get_this();
	protected:
		std::string type;
		std::string profile;
		int license;
		std::string place;
};