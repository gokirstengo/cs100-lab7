#include "gtest/gtest.h"

//#include "op_test.hpp"
//#include "tree_test.hpp"
#include "factory_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
