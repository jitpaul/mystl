#include "gtest/gtest.h"
#include <myvector.h>

namespace {

class TestFixture : public ::testing::Test {
 
 protected:

  TestFixture() {
  }

  ~TestFixture() override {
  }

  void SetUp() override {
     // Code here will be called immediately after the constructor (right
     // before each test).
  }

  void TearDown() override {
     // Code here will be called immediately after each test (right
     // before the destructor).
  }

};

};

TEST_F(TestFixture, TestSizeTrue) {
  mystd::myvector<int> array;
  EXPECT_EQ(array.size(), 0);
  EXPECT_EQ(array.capacity(), 0);
}

TEST_F(TestFixture, TestSizeFalse) {
    mystd::myvector<int> array;
    array.push_back(1);
    EXPECT_NE(array.size(), 1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}