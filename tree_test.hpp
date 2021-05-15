#ifndef __TREE_TEST_HPP__
#define __TREE_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "operator.hpp"

TEST(TreeTest, AddMultMinusTest) {
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two);
    
    EXPECT_EQ(minus->stringify(), "((3 + (7 * 4)) - 2)");
    EXPECT_EQ(minus->evaluate(), 29);
}

TEST(TreeTest, AddDivMinusTest) {
    Base* ten = new Op(10);
    Base* fifteen = new Op(15);
    Base* eight = new Op(8);
    Base* three = new Op(3);
    Base* add = new Add(ten, fifteen);
    Base* minus = new Sub(eight, three);
    Base* div = new Div(add, minus);

    EXPECT_EQ(div->stringify(), "((10 + 15) / (8 - 3))");
    EXPECT_EQ(div->evaluate(), 5);
}

TEST(TreeTest, AddDivMinusMultPowTest) {
    Base* ten = new Op(10);
    Base* fifteen = new Op(15);
    Base* eight = new Op(8);
    Base* three = new Op(3);
    Base* two = new Op(2);
    Base* add = new Add(ten, fifteen);
    Base* minus = new Sub(eight, three);
    Base* div = new Div(add, minus);
    Base* mult = new Mult(div, two);
    Base* pow = new Pow(mult, two);

    EXPECT_EQ(pow->stringify(), "((((10 + 15) / (8 - 3)) * 2) ** 2)");
    EXPECT_EQ(pow->evaluate(), 100);
}

TEST(TreeTest, DivPowTest) {
    Base* sixteen = new Op(16);
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* div = new Div(one, two);
    Base* pow = new Pow(sixteen, div);

    EXPECT_EQ(pow->stringify(), "(16 ** (1 / 2))");
    EXPECT_EQ(pow->evaluate(), 4);
}

TEST(TreeTest, MultMinusTest) {
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult1 = new Mult(seven, three);
    Base* mult2 = new Mult(two, four);
    Base* minus = new Sub(mult1, mult2);
    
    EXPECT_EQ(minus->stringify(), "((7 * 3) - (2 * 4))");
    EXPECT_EQ(minus->evaluate(), 13);
}

TEST(TreeTest, DivPowAddTest) {
    Base* sixteen = new Op(16);
    Base* seven = new Op(7);
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* div = new Div(one, two);
    Base* pow = new Pow(sixteen, div);
    Base* add = new Add(pow, seven);

    EXPECT_EQ(add->stringify(), "((16 ** (1 / 2)) + 7)");
    EXPECT_EQ(add->evaluate(), 11);
}



#endif //__TREE_TEST_HPP__

