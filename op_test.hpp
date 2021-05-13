#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "operator.hpp"

//Op class tests
TEST(OpTest, OpEvaluatePositive) {
    Op* test1 = new Op(8);
    EXPECT_DOUBLE_EQ(test1->evaluate(), 8);
}

TEST(OpTest, OpEvaluateNegative) {
    Op* test2 = new Op(-8);
    EXPECT_DOUBLE_EQ(test2->evaluate(), -8);
}

TEST(OpTest, OpEvaluateZero) {
    Op* test3 = new Op(0);
    EXPECT_DOUBLE_EQ(test3->evaluate(), 0);
}

TEST(OpTest, OpStringPositive) {
    Op* test4 = new Op(1.1);
    EXPECT_EQ(test4->stringify(), "1.100000");
}

TEST(OpTest, OpStringNegative) {
    Op* test5 = new Op(-1.12);
    EXPECT_EQ(test5->stringify(), "-1.120000");
}
TEST(OpTest, OpStringZero) {
    Op* test6 = new Op(0);
    EXPECT_EQ(test6->stringify(), "0");
}

//Rand class tests
TEST(RandTest, RandStayInRange) {
    Base* val = new Rand();

    EXPECT_LT(-1, val->evaluate());
    EXPECT_LT(val->evaluate(), 100);
}
TEST(RandTest, RnadStringify) {
    Base* val = new Rand();

    EXPECT_EQ(val->stringify(), to_string(static_cast<int>(val->evaluate())));
}

//Sub class tests
TEST(SubTest, SubPositiveTest) {
    Base* leftChild = new Op(5);
    Base* rightChild = new Op(2);
    Base* minus = new Sub(leftChild, rightChild);

    EXPECT_EQ(minus->evaluate(), 3);
    EXPECT_EQ(minus->stringify(), "(5 - 2)");
}

TEST(SubTest, SubNegativeTest) {
    Base* leftChild = new Op(1);
    Base* rightChild = new Op(3);
    Base* minus = new Sub(leftChild, rightChild);

    EXPECT_EQ(minus->evaluate(), -2);
    EXPECT_EQ(minus->stringify(), "(1 - 3)");
}

TEST(SubTest, SubZeroTest) {
    Base* leftChild = new Op(7);
    Base* rightChild = new Op(7);
    Base* minus = new Sub(leftChild, rightChild);

    EXPECT_EQ(minus->evaluate(), 0);
    EXPECT_EQ(minus->stringify(), "(7 - 7)"); 
}

//Add class tests
TEST(AddTest, AddPositiveTest) {
    Base* leftChild = new Op(5);
    Base* rightChild = new Op(5);
    Base* add = new Add(leftChild, rightChild);

    EXPECT_EQ(add->evaluate(), 10);
    EXPECT_EQ(add->stringify(), "(5 + 5)");
}

TEST(AddTest, AddNegativeTest) {
    Base* leftChild = new Op(1);
    Base* rightChild = new Op(-4);
    Base* add = new Add(leftChild, rightChild);

    EXPECT_EQ(add->evaluate(), -3);
    EXPECT_EQ(add->stringify(), "(1 + -4)");
}

TEST(AddTest, AddTwoNegativeTest) {
    Base* leftChild = new Op(-1);
    Base* rightChild = new Op(-4);
    Base* add = new Add(leftChild, rightChild);

    EXPECT_EQ(add->evaluate(), -5);
    EXPECT_EQ(add->stringify(), "(-1 + -4)");
}

TEST(AddTest, AddZeroTest) {
    Base* leftChild = new Op(7.777);
    Base* rightChild = new Op(0);
    Base* add = new Add(leftChild, rightChild);

    EXPECT_DOUBLE_EQ(add->evaluate(), 7.777);
    EXPECT_EQ(add->stringify(), "(7.777000 + 0)");
}

//Mult class tests
TEST(MultTest, MultPositiveTest) {
    Base* leftChild = new Op(5);
    Base* rightChild = new Op(5);
    Base* mult = new Mult(leftChild, rightChild);

    EXPECT_EQ(mult->evaluate(), 25);
    EXPECT_EQ(mult->stringify(), "(5 * 5)");
}

TEST(MultTest, MultNegativeTest) {
    Base* leftChild = new Op(2);
    Base* rightChild = new Op(-4);
    Base* mult = new Mult(leftChild, rightChild);

    EXPECT_EQ(mult->evaluate(), -8);
    EXPECT_EQ(mult->stringify(), "(2 * -4)");
}

TEST(MultTest, MultTwoDecimalTest) {
    Base* leftChild = new Op(0.5);
    Base* rightChild = new Op(0.125);
    Base* mult = new Mult(leftChild, rightChild);

    EXPECT_DOUBLE_EQ(mult->evaluate(), 0.062500);
    EXPECT_EQ(mult->stringify(), "(0.500000 * 0.125000)");
}

TEST(MultTest, MultTwoNegativeTest) {
    Base* leftChild = new Op(-3);
    Base* rightChild = new Op(-7);
    Base* mult = new Mult(leftChild, rightChild);

    EXPECT_EQ(mult->evaluate(), 21);
    EXPECT_EQ(mult->stringify(), "(-3 * -7)");
}

TEST(MultTest, MultZeroTest) {
    Base* leftChild = new Op(7.777);
    Base* rightChild = new Op(0);
    Base* mult = new Mult(leftChild, rightChild);

    EXPECT_DOUBLE_EQ(mult->evaluate(), 0);
    EXPECT_EQ(mult->stringify(), "(7.777000 * 0)");
}

//Div class tests
TEST(DivTest, DivPositiveRightTest) {
    Base* leftChild = new Op(6);
    Base* rightChild = new Op(12);
    Base* div = new Div(leftChild, rightChild);

    EXPECT_DOUBLE_EQ(div->evaluate(), 0.5);
    EXPECT_EQ(div->stringify(), "(6 / 12)");
}
TEST(DivTest, DivEqualTest) {
    Base* leftChild = new Op(5);
    Base* rightChild = new Op(5);
    Base* div = new Div(leftChild, rightChild);

    EXPECT_EQ(div->evaluate(), 1);
    EXPECT_EQ(div->stringify(), "(5 / 5)");
}
TEST(DivTest, DivPositiveleftChildTest) {
    Base* leftChild = new Op(25);
    Base* rightChild = new Op(5);
    Base* div = new Div(leftChild, rightChild);

    EXPECT_EQ(div->evaluate(), 5);
    EXPECT_EQ(div->stringify(), "(25 / 5)");
}
TEST(DivTest, DivZeroTest) {
    Base* leftChild = new Op(0);
    Base* rightChild = new Op(33);
    Base* div = new Div(leftChild, rightChild);

    EXPECT_EQ(div->evaluate(), 0);
    EXPECT_EQ(div->stringify(), "(0 / 33)");
}
TEST(DivTest, DivPositiveUndefinedTest) {
    Base* leftChild = new Op(15);
    Base* rightChild = new Op(0);
    Base* div = new Div(leftChild, rightChild);

    EXPECT_EQ(div->evaluate(), numeric_limits<double>::infinity());
    EXPECT_EQ(div->stringify(), "(15 / 0)");
}
TEST(DivTest, DivNegativeUndefinedTest) {
    Base* leftChild = new Op(-20);
    Base* rightChild = new Op(0);
    Base* div = new Div(leftChild, rightChild);

    EXPECT_EQ(div->evaluate(), -numeric_limits<double>::infinity());
    EXPECT_EQ(div->stringify(), "(-20 / 0)");
}
TEST(DivTest, DivIndeterminateTest) {
    Base* leftChild = new Op(0);
    Base* rightChild = new Op(0);
    Base* div = new Div(leftChild, rightChild);

    // EXPECT_EQ(div->evaluate(), numeric_limits<double>::quiet_NaN());
    EXPECT_TRUE(isnan(div->evaluate())); // cannot compare NaN to NaN
    EXPECT_EQ(div->stringify(), "(0 / 0)");
}

//Pow class tests
TEST(PowTest, PosExponentTest) {
    Base* leftChild = new Op(5);
    Base* rightChild = new Op(2);
    Base* pow = new Pow(leftChild, rightChild);

    EXPECT_EQ(pow->evaluate(), 25);
    EXPECT_EQ(pow->stringify(), "(5 ** 2)");
}

TEST(PowTest, NegExponentTest) {
    Base* leftChild = new Op(2);
    Base* rightChild = new Op(-1);
    Base* pow = new Pow(leftChild, rightChild);

    EXPECT_DOUBLE_EQ(pow->evaluate(), 0.5);
    EXPECT_EQ(pow->stringify(), "(2 ** -1)");
}

TEST(PowTest, DecExponentTest) {
    Base* leftChild = new Op(4);
    Base* rightChild = new Op(0.5);
    Base* pow = new Pow(leftChild, rightChild);

    EXPECT_EQ(pow->evaluate(), 2);
    EXPECT_EQ(pow->stringify(), "(4 ** 0.500000)");
}

TEST(PowTest, ZeroBaseTest) {
    Base* leftChild = new Op(0);
    Base* rightChild = new Op(2);
    Base* pow = new Pow(leftChild, rightChild);

    EXPECT_EQ(pow->evaluate(), 0);
    EXPECT_EQ(pow->stringify(), "(0 ** 2)");
}
    
TEST(PowTest, NegBaseTest) {
    Base* leftChild = new Op(-1);
    Base* rightChild = new Op(3);
    Base* pow = new Pow(leftChild, rightChild);

    EXPECT_EQ(pow->evaluate(), -1);
    EXPECT_EQ(pow->stringify(), "(-1 ** 3)");
    }

TEST(PowTest, ZeroExponentTest) {
    Base* leftChild = new Op(-7.777);
    Base* rightChild = new Op(0);
    Base* pow = new Pow(leftChild, rightChild);

    EXPECT_EQ(pow->evaluate(), 1);
    EXPECT_EQ(pow->stringify(), "(-7.777000 ** 0)");
}
#endif //__OP_TEST_HPP__
