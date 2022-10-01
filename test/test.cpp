// "Copyright [2022] Tharun V. Puthanveettil"

#include <gtest/gtest.h>
#include "pid.hpp"

TEST(dummy, should_pass) {
  EXPECT_EQ(1, 1);
}



TEST(TDD_PairB, Testsuite) {
  pid controller(1.0, 0.0, 0.25);
  controller.calcPID(0.1, 0.5);
}
