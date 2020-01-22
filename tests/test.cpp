// Copyright 2020 Paul Nolan pasha230899@gmail.com

#include <gtest/gtest.h>
#include <header.hpp>

TEST(Example, EmptyTest) { EXPECT_TRUE(true); }

TEST(STACK, first) {
  Stack<int> first;
  first.push(0);
  Stack<int> sec(std::move(first));

  sec.push(-80);
  sec.push(180);

  EXPECT_EQ(180, sec.head());
  sec.pop();
  EXPECT_EQ(-80, sec.head());
  sec.pop();
  EXPECT_EQ(0, sec.head());

  Stack<int> third;

  int a = 2903;
  third.push(a);
  a++;
  third.push(a);

  EXPECT_EQ(2904, third.head());
  third.pop();
  EXPECT_EQ(2903, third.head());
  EXPECT_TRUE(std::is_move_constructible<Stack<int>>::value);
}

TEST(Stack, second) {
  EXPECT_TRUE(std::is_move_constructible<Stack<int>>::value);

  Stack<std::string> first;
  first.push("string 1!");

  first.push("string 2!");
  std::string test = "string 2!";
  //  EXPECT_EQ(test, first.pop());

  //   test = "string 1!";
  EXPECT_EQ(test, first.head());

  Stack<std::string> second(std::move(first));

  EXPECT_EQ(test, second.head());
}
