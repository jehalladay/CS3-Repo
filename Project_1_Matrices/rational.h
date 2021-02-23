#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class RationalNumber {
    private:
        int num, den;
    public:
        // constructors
        RationalNumber();
        RationalNumber(int num, int den);
        // getters and setters
        int get_num();
        int get_den();
        void set_num(int in);
        void set_den(int in);
        // testing functions
        void print_to_file(ofstream &out);
        // reducing function
        void reduce();
        // overloaded operators
        friend RationalNumber operator +(RationalNumber first, RationalNumber second);
        friend RationalNumber operator -(RationalNumber first, RationalNumber second);
        friend RationalNumber operator *(RationalNumber first, RationalNumber second);
        friend RationalNumber operator /(RationalNumber first, RationalNumber second);
        friend istream& operator >>(istream &ins, RationalNumber &number);
        friend ostream& operator <<(ostream &ofs, RationalNumber number);
};

RationalNumber operator +(RationalNumber first, RationalNumber second);
RationalNumber operator -(RationalNumber first, RationalNumber second);
RationalNumber operator *(RationalNumber first, RationalNumber second);
RationalNumber operator /(RationalNumber first, RationalNumber second);
istream& operator >>(istream &ins, RationalNumber &number);
ostream& operator <<(ostream &ofs, RationalNumber number);