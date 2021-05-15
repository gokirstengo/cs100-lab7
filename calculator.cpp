#include <iostream>
#include "factory.hpp"

using namespace std;

int main(int argc, char **argv) {
    Factory factory;
    Base* tree = factory.parse(argv, argc);

    if (tree) {
        cout << tree->stringify() << " = " << tree->evaluate() << endl;
    }
    
    delete tree;

    return 0;
}

