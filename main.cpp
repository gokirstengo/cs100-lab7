#include <iostream>

#include "base.hpp"
#include "op.hpp"
#include "operator.hpp"

using namespace std;

int main() {

    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* ten = new Op(10);
    Base* fifteen = new Op(15);
    Base* eight = new Op(8);
    Base* sixteen = new Op(16);
    Base* one = new Op(1);
    
    Base* mult1 = new Mult(seven, four);
    Base* add1 = new Add(three, mult1);
    Base* minus1 = new Sub(add1, two);
    
    Base* add2 = new Add(ten, fifteen);
    Base* minus2 = new Sub(eight, three);
    Base* div2 = new Div(add2, minus2);
    Base* mult2 = new Mult(div2, two);
    Base* pow2 = new Pow(mult2, two);
    
    Base* div3 = new Div(one, two);
    Base* pow3 = new Pow(sixteen, div3);
    
    Base* mult3 = new Mult(seven, three);
    Base* mult4 = new Mult(two, four);
    Base* minus3 = new Sub(mult3, mult4);
    
    Base* add3 = new Add(pow3, seven);
    
    cout << minus1->stringify() << " = " << minus1->evaluate() << endl;
    cout << div2->stringify() << " = " << div2->evaluate() << endl;
    cout << pow2->stringify() << " = " << pow2->evaluate() << endl;
    cout << pow3->stringify() << " = " << pow3->evaluate() << endl;
    cout << minus3->stringify() << " = " << minus3->evaluate() << endl;
    cout << add3->stringify() << " = " << add3->evaluate() << endl;
    
    return 0;
}
