
#include "LeapTestCase.h"

#include <Functions.h>

TEST(IsLeapTest, Leap1){
  EXPECT_ANY_THROW(IsLeap(-1));
  EXPECT_EQ(false,IsLeap(2019));
  EXPECT_EQ(true,IsLeap(2020));
  EXPECT_EQ(true,IsLeap(1600));
  EXPECT_EQ(false,IsLeap(1700));
}

TEST(GetMonthTest, Month1){
  EXPECT_ANY_THROW(GetMonthDays(-12,-12));
  EXPECT_EQ(29,GetMonthDays(2020,2));
  EXPECT_EQ(28,GetMonthDays(2019,2));
  EXPECT_EQ(31,GetMonthDays(2019,3));
  EXPECT_EQ(30,GetMonthDays(2019,4));
}

