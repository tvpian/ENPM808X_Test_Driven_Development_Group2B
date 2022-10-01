// "Copyright [2022] Tharun V. Puthanveettil"

#include <gtest/gtest.h>
#include "pid.hpp"

TEST(dummy, should_pass) {
  EXPECT_EQ(1, 1);
}



TEST(TDD_PairB, Testsuite) {
  double param1, param2, param3;
  pid controller(1.0, 0.0, 0.25);
  controller.calcPID(0.1, 0.5);
  param1 = controller.getParam("kp");
  param2 = controller.getParam("ki");
  param3 = controller.getParam("kd");
  EXPECT_EQ(param1,1.0);
  EXPECT_EQ(param2,0.0);
  EXPECT_EQ(param3,0.25);
  EXPECT_EQ(controller.getParam("nothing"),0);
}
