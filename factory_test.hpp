#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include "gtest/gtest.h"
#include "factory.hpp"
#include "op.hpp"
#include "operator.hpp"

TEST(FactoryTest, AddTest) {
    char ** input = new char * [4];
    input[0] = "filler";
    input[1] = "3.5";
    input[2] = "+";
    input[3] = "7";

    int size = 4;
    Factory *f = new Factory();
    Base *b = f->parse(input, size);

    EXPECT_EQ(b->stringify(), "(3.500000 + 7)");
    EXPECT_EQ(b->evaluate(), 10.5);
}

TEST(FactoryTest, MultTest) {
    char ** input = new char * [4];
    input[0] = "filler";
    input[1] = "-3.5";
    input[2] = "*";
    input[3] = "8";

    int size = 4;
    Factory *f = new Factory();
    Base *b = f->parse(input, size);

    EXPECT_EQ(b->stringify(), "(-3.500000 * 8)");
    EXPECT_EQ(b->evaluate(), -28);
}

TEST(FactoryTest, DivTest) {
    char ** input = new char * [4];
    input[0] = "filler";
    input[1] = "7";
    input[2] = "/";
    input[3] = "3.5";

    int size = 4;
    Factory *f = new Factory();
    Base *b = f->parse(input, size);

    EXPECT_EQ(b->stringify(), "(7 / 3.500000)");
    EXPECT_EQ(b->evaluate(), 2);
}

TEST(FactoryTest, PowTest) {
    char ** input = new char * [4];
    input[0] = "filler";
    input[1] = "3.5";
    input[2] = "**";
    input[3] = "2";

    int size = 4;
    Factory *f = new Factory();
    Base *b = f->parse(input, size);

    EXPECT_EQ(b->stringify(), "(3.500000 ** 2)");
    EXPECT_EQ(b->evaluate(), 12.25);
}

TEST(FactoryTest, SubTest) {
    char ** input = new char * [4];
    input[0] = "filler";
    input[1] = "7";
    input[2] = "-";
    input[3] = "3.5";

    int size = 4;
    Factory *f = new Factory();
    Base *b = f->parse(input, size);

    EXPECT_EQ(b->stringify(), "(7 - 3.500000)");
    EXPECT_EQ(b->evaluate(), 3.5);
}


TEST(FactoryTest, AddMultMinusTest) {
    char ** input = new char * [8];
    input[0] = "filler";
    input[1] = "3";
    input[2] = "+";
    input[3] = "7";
    input[4] = "*";
    input[5] = "4";
    input[6] = "-";
    input[7] = "2";
    
    int size = 8;
    Factory *f = new Factory();
    Base *b = f->parse(input, size);
    
    EXPECT_EQ(b->stringify(), "(((3 + 7) * 4) - 2)");
    EXPECT_EQ(b->evaluate(), 38);
}

TEST(FactoryTest, AddDivMinusTest) {
    char ** input = new char * [8];
    input[0] = "filler";
    input[1] = "-10";
    input[2] = "+";
    input[3] = "14";
    input[4] = "/";
    input[5] = "8";
    input[6] = "-";
    input[7] = "3";
    
    int size = 8;
    Factory *f = new Factory();
    Base *b = f->parse(input, size);

    EXPECT_EQ(b->stringify(), "(((-10 + 14) / 8) - 3)");
    EXPECT_EQ(b->evaluate(), -2.5);
}

TEST(FactoryTest, AddDivMinusMultPowTest) {
    char ** input = new char * [12];
    input[0] = "filler";
    input[1] = "10";
    input[2] = "+";
    input[3] = "54";
    input[4] = "/";
    input[5] = "8";
    input[6] = "-";
    input[7] = "3";
    input[8] = "*";
    input[9] = "2";
    input[10] = "**";
    input[11] = "2";

    
    int size = 12;
    Factory *f = new Factory();
    Base *b = f->parse(input, size);


    EXPECT_EQ(b->stringify(), "(((((10 + 54) / 8) - 3) * 2) ** 2)");
    EXPECT_EQ(b->evaluate(), 100);
}

TEST(FactoryTest, DivPowTest) {
    char ** input = new char * [6];
    input[0] = "filler";
    input[1] = "5";
    input[2] = "**";
    input[3] = "2";
    input[4] = "/";
    input[5] = "2";
    
    int size = 6;
    Factory *f = new Factory();
    Base *b = f->parse(input, size);

    EXPECT_EQ(b->stringify(), "((5 ** 2) / 2)");
    EXPECT_EQ(b->evaluate(), 12.5);
}

TEST(FactoryTest, MultMinusTest) {
    char ** input = new char * [8];
    input[0] = "filler";
    input[1] = "7";
    input[2] = "*";
    input[3] = "3";
    input[4] = "-";
    input[5] = "2";
    input[6] = "*";
    input[7] = "4";
    
    int size = 8;
    Factory *f = new Factory();
    Base *b = f->parse(input, size);

    
    EXPECT_EQ(b->stringify(), "(((7 * 3) - 2) * 4)");
    EXPECT_EQ(b->evaluate(), 76);
}

TEST(FactoryTest, DivPowAddTest) {
    char ** input = new char * [8];
    input[0] = "filler";
    input[1] = "4";
    input[2] = "/";
    input[3] = "2";
    input[4] = "+";
    input[5] = "7";
    input[6] = "**";
    input[7] = "2";
    
    int size = 8;
    Factory *f = new Factory();
    Base *b = f->parse(input, size);


    EXPECT_EQ(b->stringify(), "(((4 / 2) + 7) ** 2)");
    EXPECT_EQ(b->evaluate(), 81);
}

TEST(FactoryTest, InvalidOpTest) {
    char ** input = new char * [8];
    input[0] = "filler";
    input[1] = "a";
    input[2] = "/";
    input[3] = "b";
    input[4] = "+";
    input[5] = "7";
    input[6] = "**";
    input[7] = "2";
    
    int size = 8;
    Factory *f = new Factory();
    Base *b = f->parse(input, size);
    
    EXPECT_EQ(b, nullptr);
    
}

TEST(FactoryTest, InvalidOperatorTest) {
    char ** input = new char * [8];
    input[0] = "filler";
    input[1] = "1";
    input[2] = "b";
    input[3] = "2";
    input[4] = "c";
    input[5] = "7";
    input[6] = "**";
    input[7] = "2";
    
    int size = 8;
    Factory *f = new Factory();
    Base *b = f->parse(input, size);

    EXPECT_EQ(b, nullptr);
}



#endif //__FACTORY_TEST_HPP__

