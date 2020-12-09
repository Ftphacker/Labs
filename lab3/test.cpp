#include <gtest/gtest.h>
#include <iostream>
#include "lab3.h"

TEST(deckTest, intTest) { 
	deck my_deck_base_init;
    EXPECT_EQ (52, my_deck_base_init.get_N());
    deck my_deck_int_init(30);
    EXPECT_EQ (30, my_deck_int_init.get_N());
}

TEST(deckTest, peregruzTest) { 
	deck my_deck_int_init(51);
	++my_deck_int_init;
    EXPECT_EQ (52, my_deck_int_init.get_N());
    deck my_deck_int_init2(30);
    ++my_deck_int_init2;
    EXPECT_EQ (31, my_deck_int_init2.get_N());
}

TEST(deckTest, peregruz2Test) { 
	deck my_deck_base_init;
	my_deck_base_init.sort_deck();
    EXPECT_EQ (2, my_deck_base_init[52]);
    EXPECT_EQ ('b', my_deck_base_init(52));
}
/*TEST(deckTest, isklTest) { 
	deck my_deck_base_init;
	ASSERT_THROW(my_deck_base_init['a'], 'invalid_argument err');
}*/




int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}