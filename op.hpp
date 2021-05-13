#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <ctime>

using namespace std;

class Op : public Base {
    protected:
        double value;
    public:
        Op(double value) : Base() {this->value = value; }
        virtual double evaluate() { return value; }
        virtual std::string stringify()
        { 
	    int i = value;
            if((value - i) > 0.000001 || (i - value) > 0.000001)
            {
                return std::to_string(value);
            }
            else
            {
                return std::to_string(i);
            }
	}
};

class Rand : public Base {
    private:
        double value;
    public:
        Rand() : Base() {
	    srand(time(0));
	    value = rand() % 100;
        }
        virtual double evaluate() { return value; }
        virtual std::string stringify() { 
            if (value == static_cast<int>(value)) {
                return to_string(static_cast<int>(value)); 
            }
            else {
                return to_string(value);
            }
        }
};

class SevenOpMock: public Base {
    public:
        SevenOpMock() { }

        virtual double evaluate() { return 7.5; }
        virtual string stringify() { return "7.5"; }
};

class NegativeEightOpMock: public Base {
    public:
        NegativeEightOpMock() { }

        virtual double evaluate() { return -8; }
        virtual string stringify() { return "-8"; }
};

class ZeroOpMock: public Base {
    public:
        ZeroOpMock() { }

        virtual double evaluate() { return 0; }
        virtual string stringify() { return "0"; }
};

#endif //__OP_HPP__
