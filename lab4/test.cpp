#include <gtest/gtest.h>
#include <iostream>
#include "Radio.h"

TEST(AgencyTest, nameTest) {
	Agency new_agency("WWW"); 
	std::string pobg, pobg2;
	pobg = "WWW";
	pobg2 = new_agency.get_name();
	ASSERT_TRUE(pobg == pobg2);
    ASSERT_EQ(NULL, new_agency.obj);
    ASSERT_EQ(NULL, new_agency.next);
}

TEST(DescriptorTest, allTest) { 
	Descriptor new_descriptor;
	std::string pobg, pobg2;
	pobg = "";
	pobg2 = new_descriptor.get_type();
	ASSERT_TRUE(pobg == pobg2);
	pobg = "";
	pobg2 = new_descriptor.get_place();
	ASSERT_TRUE(pobg == pobg2);
	pobg = "";
	pobg2 = new_descriptor.get_profile();
	ASSERT_TRUE(pobg == pobg2);
	EXPECT_EQ(new_descriptor.get_license(), 0);
	Descriptor new_descriptor2(1, "Tele", "qwe", "USA");
	pobg = "Tele";
	pobg2 = new_descriptor2.get_type();
	ASSERT_TRUE(pobg == pobg2);
	pobg = "USA";
	pobg2 = new_descriptor2.get_place();
	ASSERT_TRUE(pobg == pobg2);
	pobg = "qwe";
	pobg2 = new_descriptor2.get_profile();
	ASSERT_TRUE(pobg == pobg2);
	EXPECT_EQ(new_descriptor2.get_license(), 1);
}

TEST(RadioTest, allTest) { 
	Radio new_radio;
	range obj;
	obj.x = 0;
	obj.y = 0;
	std::string pobg, pobg2;
	pobg = "";
	pobg2 = new_radio.get_type();
	ASSERT_TRUE(pobg == pobg2);
	pobg = "";
	pobg2 = new_radio.get_place();
	ASSERT_TRUE(pobg == pobg2);
	pobg = "";
	pobg2 = new_radio.get_profile();
	ASSERT_TRUE(pobg == pobg2);
	EXPECT_EQ(new_radio.get_license(), 0);
	range pobg3 = new_radio.get_obj();
	ASSERT_TRUE((pobg3.x == obj.x) && (pobg3.y == obj.y));
	EXPECT_EQ(new_radio.get_frequency(), 0);
	obj.x = 5;
	obj.y = 7;
	new_radio.chage_obj(obj);
	pobg3 = new_radio.get_obj();
	ASSERT_TRUE((pobg3.x == obj.x) && (pobg3.y == obj.y));
	new_radio.chage_frequency(10);
	EXPECT_EQ(new_radio.get_frequency(), 10);
}

TEST(PrintTest, allTest) { 
	Print new_print;
	std::string pobg, pobg2;
	pobg = "";
	pobg2 = new_print.get_type();
	ASSERT_TRUE(pobg == pobg2);
	pobg = "";
	pobg2 = new_print.get_place();
	ASSERT_TRUE(pobg == pobg2);
	pobg = "";
	pobg2 = new_print.get_profile();
	ASSERT_TRUE(pobg == pobg2);
	EXPECT_EQ(new_print.get_license(), 0);
	EXPECT_EQ(new_print.get_period(), 0);
	EXPECT_EQ(new_print.get_tiraj(), 0);
	new_print.change_period(10);
	EXPECT_EQ(new_print.get_period(), 10);
	new_print.change_tiraj(10);
	EXPECT_EQ(new_print.get_tiraj(), 10);
}

TEST(TeleTest, allTest) { 
	Tele new_tele;
	std::string pobg, pobg2;
	pobg = "";
	pobg2 = new_tele.get_type();
	ASSERT_TRUE(pobg == pobg2);
	pobg = "";
	pobg2 = new_tele.get_place();
	ASSERT_TRUE(pobg == pobg2);
	pobg = "";
	pobg2 = new_tele.get_profile();
	ASSERT_TRUE(pobg == pobg2);
	EXPECT_EQ(new_tele.get_license(), 0);
	EXPECT_EQ(new_tele.get_channel(), 0);
	Tele new_tele2(10, 1, "Tele", "qwe", "USA");
	pobg = "Tele";
	pobg2 = new_tele2.get_type();
	ASSERT_TRUE(pobg == pobg2);
	pobg = "USA";
	pobg2 = new_tele2.get_place();
	ASSERT_TRUE(pobg == pobg2);
	pobg = "qwe";
	pobg2 = new_tele2.get_profile();
	ASSERT_TRUE(pobg == pobg2);
	EXPECT_EQ(new_tele2.get_license(), 1);
	EXPECT_EQ(new_tele2.get_channel(), 10);
}


int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}