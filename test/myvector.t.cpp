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

TEST_F(TestFixture, TestSize1) {
  mystd::myvector<int> array;
  EXPECT_EQ(array.size(), 0);
  EXPECT_EQ(array.capacity(), 0);
}

TEST_F(TestFixture, TestSize2) {
    mystd::myvector<int> array;
    array.push_back(1);
    EXPECT_NE(array.size(), 0);
}

TEST_F(TestFixture, TestPushPopSize){
    mystd::myvector<int> array;
    array.push_back(5);
    array.push_back(8);
    EXPECT_EQ(array.size(),2);
    array.pop_back();
    array.pop_back();
    EXPECT_EQ(array.size(),0);
}

TEST_F(TestFixture, TestCopy){
    mystd::myvector<int> array;
    array.push_back(5);
    array.push_back(6);
    mystd::myvector<int> array2(array);
    EXPECT_EQ(array2.size(),2);
    EXPECT_EQ(array2.back(),6);
    array2.pop_back();
    EXPECT_EQ(array2.back(),5);
    array2.pop_back();
    EXPECT_EQ(array.size(), 2);
    EXPECT_EQ(array2.size(), 0);
}

TEST_F(TestFixture, TestOverload){
    mystd::myvector<int> array;
    array.push_back(4);
    EXPECT_EQ(array[0],4);
}

TEST_F(TestFixture, TestInitializerList){
    mystd::myvector<int> array = {1,2,3,4};
    EXPECT_EQ(array.size(),4);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}