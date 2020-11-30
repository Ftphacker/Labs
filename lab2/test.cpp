#include "gtest/gtest.h"
#include "lab2.h"
#include <iostream>

#define def_r 1
#define def_t 1

TEST(LenTest, FLenTest) { 
	Ast astr(def_r);
    EXPECT_FLOAT_EQ (1.06211, astr.len_part_arc(def_t));
}
 
TEST(LenAllTest, FLenAllTest) { 
	Ast astr(def_r);
    EXPECT_FLOAT_EQ (6, astr.len_all_arc());
}

TEST(rocTest, FrocTest) { 
	Ast astr(def_r);
    EXPECT_FLOAT_EQ (1.3639462, astr.roc(def_t));
}

TEST(areaTest, FareaTest) { 
	Ast astr(def_r);
    EXPECT_FLOAT_EQ (4.71239, astr.area());
}

/*TEST(xayTest, xayTest) { 
	Ast astr;
    EXPECT_EQ (18.0, astr.xay(def_t));
}*/

TEST(xfyTest, FxfyTest) { 
	Ast astr(def_r);
    EXPECT_EQ (0, astr.xfy(def_t));
}

TEST(xayTest, FxfyTest) { 
	Ast astr(def_r);
    EXPECT_FLOAT_EQ (0.15772861, astr.return_x(def_t));
    EXPECT_FLOAT_EQ (0.595823, astr.return_y(def_t));
}

TEST(input_rTest, inputTest) { 
	Ast astr(def_r);
    ASSERT_TRUE(astr.input_r(1));
    //ASSERT_FALSE(astr.input_r(a));
}

TEST(contructTest, constructTest) { 
	Ast astr(def_r);
    EXPECT_EQ (0, (def_t));
}

int main(int argc, char **argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}