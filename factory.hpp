#ifndef __FACTORY_H__
#define __FACTORY_H__

#include <iostream>
#include <cstdlib>
#include "base.hpp"
#include "op.hpp"
#include "operator.hpp"
#include <string.h>
#include <string>
#include <cctype>

using namespace std;

struct error {
    const char* message;
    const char* input;
    error(const char* input, const char* message ): message(message), input(input) {}

    void what() {
        cout << "\""<< input << "\"" <<  message << endl;
    }
};

class Factory {
private:
   Base* base;

   Base* validateOperator(char* input, Base* prev, Base* curr) {
        Base* new_operator;

        if (strlen(input) >= 2 && input[1] != '*') {
            return nullptr;
        }

        switch (input[0]) {
            case '*':
                if (strlen(input) == 2 && input[1] == '*') {
                    new_operator = new Pow(prev,curr);
                }
                else {
                    new_operator = new Mult(prev, curr);
                }
                break;
            case '+':
                new_operator = new Add(prev, curr);
                break;
            case '/':
                new_operator = new Div(prev, curr);
                break;
            case '-':
                new_operator = new Sub(prev, curr);
                break;
            default:
                new_operator = nullptr;
                break;
        }

        return new_operator;
    }

    int str_to_int(char* string) {
        unsigned size = strlen(string);
        int result = 0;
        bool neg_flag = false;
        for (unsigned i = 0; i < size; ++i) {
            result *= 10;
            if (i == 0 && string[i] == '-') {
                neg_flag = true;
            }
            else if (isdigit(string[i])) {
                result += string[i] - '0';
            }
            else {
                throw(error(string, " is not a numeric operand"));
            }
        }
        if (neg_flag) {
            result *= -1;
        }
        return result;
    }
public:
   Factory():base(0) {}

    Base * parse(char** input, unsigned size) {
        Base* prev = 0;
        Base* curr = 0;

        if (!(size >= 3 && size % 2 == 0)) {
            cout << "incorrect input" << endl;
            return nullptr;
        }

        for (unsigned i = 1; i < size; i+=2) {
            try {
                curr = new Op((double)str_to_int(input[i]));
            }
            catch(error message) {
                message.what();
                return nullptr;
            }

            if (prev) {
                curr = validateOperator(input[i-1], prev, curr);
                if (!curr) {
                    cout << "incorrect input, expected operator" << endl;
                    return nullptr;
                }
            }

            prev = curr;
        }
        delete base;
        this->base = curr;

        return base;
    }
};
#endif
