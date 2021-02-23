#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "rational.h"

using namespace std;

RationalNumber::RationalNumber() {
    num = 0;
    den = 1;
}

RationalNumber::RationalNumber(int numerator, int denominator) {
    if(denominator != 0) {
        num = numerator;
        den = denominator;
        reduce();
    } else {
        cout << "Cannot set Denominator to 0" << endl;
    }
}

// getters and setters
int RationalNumber::get_num() {
    return num;
}

int RationalNumber::get_den() {
    return den;
}

void RationalNumber::set_num(int in) {
    num = in;
    reduce();
}

void RationalNumber::set_den(int in) {
    if(in != 0) {
        den = in;
        reduce();
    } else {
        cout << "Cannot set denominator to 0" << endl;
    }
}

// testing functions
void RationalNumber::print_to_file(ofstream &out) {
    out << "Numerator = " << num << endl;
    out << "Denominator = " << den << endl;
}

// reducing function
void RationalNumber::reduce() {
    int smallest, i;
    if(num == 0) {
        den = 1;
        return;
    } else if(den < 0) {
        num *= -1;
        den *= -1;
    }

    if(abs(num) == den) {
        num /= den;
        den /= den;
        return;
    } else if (num > den) {
        smallest = abs(den);
    } else {
        smallest = abs(num);
    }

    for(i = smallest; i >= 2; i--) {
        if(num % i == 0 && den % i == 0) {
            num /= i;
            den /= i;
        }
    }
}


RationalNumber operator +(RationalNumber first, RationalNumber second) {
    int fNum, fDen, sNum, sDen, nNum, nDen;
    RationalNumber newNumber;
    fNum = first.num;
    fDen = first.den;
    sNum = second.num;
    sDen = second.den;

    if(fDen == sDen) {
        nDen = fDen;
        nNum = fNum + sNum;
    } else {
        nDen = fDen * sDen;
        nNum = (fNum * sDen) + (sNum * fDen);
    }

    newNumber.num = nNum;
    newNumber.den = nDen;
    newNumber.reduce();

    return newNumber;
}

RationalNumber operator -(RationalNumber first, RationalNumber second) {
    int fNum, fDen, sNum, sDen, nNum, nDen;
    RationalNumber newNumber;

    fNum = first.num;
    fDen = first.den;
    sNum = second.num;
    sDen = second.den;

    if(fDen == sDen) {
        nDen = fDen;
        nNum = fNum - sNum;
    } else {
        nDen = fDen * sDen;
        nNum = (fNum * sDen) - (sNum * fDen);
    }

    newNumber.num = nNum;
    newNumber.den = nDen;
    newNumber.reduce();

    return newNumber;
}

RationalNumber operator *(RationalNumber first, RationalNumber second) {
    RationalNumber newNumber(first.num * second.num, first.den * second.den);
    newNumber.reduce();
    return newNumber;
}

RationalNumber operator /(RationalNumber first, RationalNumber second) {
    RationalNumber newNumber;
    if(second.num == 0) {
        cout << "Cannot divide by 0" << endl;
    } else {
        newNumber.num = first.num * second.den;
        newNumber.den = second.num * first.den;
        newNumber.reduce();
    }
    
    return newNumber;
    
}

istream& operator >>(istream &ins, RationalNumber &number) {
    char ch;
    int num, den;
    ins >> num >> ch >> den;
    if(den != 0) {
        number.num = num;
        number.den = den;
        number.reduce();
    }
    return ins;
}

ostream& operator <<(ostream &ofs, RationalNumber number) {
    if(number.den == 1) {
        ofs << number.num;
    } else {
        ofs << number.num << "/" << number.den;
    }
    return ofs;
}
