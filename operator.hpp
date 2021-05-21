#ifndef __OPERATOR_HPP__
#define __OPERATOR_HPP__

#include "base.hpp"
#include "op.hpp"
#include <cmath>
#include <limits>

using namespace std;

class Operator: public Base {
    protected:
        Base* leftChild;
        Base* rightChild;
    public:
        Operator(Base* leftChild, Base* rightChild) : Base() {
            this->leftChild = leftChild;
            this->rightChild = rightChild;
        }
	~Operator(){
	    delete leftChild;
            delete rightChild;
	}
};

class Sub: public Operator {
    public:
        Sub(Base* leftChild, Base* rightChild) : Operator(leftChild, rightChild) {}
        virtual double evaluate() {
            return leftChild->evaluate() - rightChild->evaluate();
        }
        virtual string stringify() {
            string final = "";
	    final += "(";
            final += leftChild->stringify();
            final += " - ";
            final += rightChild->stringify();
	    final += ")";
            return final;
        }
};

class Add: public Operator {
    public:
        Add(Base* leftChild, Base* rightChild) : Operator(leftChild, rightChild) {}
        virtual double evaluate() {
            return leftChild->evaluate() + rightChild->evaluate();
        }
        virtual string stringify() {
            string final = "";
            final += "(";
            final += leftChild->stringify();
            final += " + ";
            final += rightChild->stringify();
            final += ")";
            return final;
        }
};

class Mult: public Operator {
    public:
        Mult(Base* leftChild, Base* rightChild) : Operator(leftChild, rightChild) {}
        virtual double evaluate() {
            return leftChild->evaluate() * rightChild->evaluate();
        }
        virtual string stringify() {
            string final = "";
            final += "(";
            final += leftChild->stringify();
            final += " * ";
            final += rightChild->stringify();
            final += ")";
            return final;
        }
};

class Div: public Operator {
    public:
        Div(Base* leftChild, Base* rightChild) : Operator(leftChild, rightChild) {}
        virtual double evaluate() {
            if (rightChild->evaluate() != 0)
                return leftChild->evaluate() / rightChild->evaluate();
            else {
                if (leftChild->evaluate() > 0)
                    return numeric_limits<double>::infinity();
                else if (leftChild->evaluate() < 0)
                    return -numeric_limits<double>::infinity();
                else
                    return numeric_limits<double>::quiet_NaN();
            }
        }
        virtual string stringify() {
            string final =  "";
            final += "(";
            final += leftChild->stringify();
            final += " / ";
            final += rightChild ->stringify();
            final += ")";
            return final;
        }
};

class Pow: public Operator {
    public:
        Pow(Base* leftChild, Base* rightChild) : Operator(leftChild, rightChild) {}
        virtual double evaluate() {
            return pow(leftChild->evaluate(), rightChild->evaluate());
        }
        virtual string stringify() {
            string final = "";
            final += "(";
            final += leftChild->stringify();
            final += " ** ";
            final += rightChild->stringify();
            final += ")";
            return final;
        }
};
#endif
