
#include "AddTestCase.h"
#include "Functions.h"
#include <gtest/gtest.h>

TEST(SumTest, Sum1){
  EXPECT_EQ(5,Add(2,3));
}

