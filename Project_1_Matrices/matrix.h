// #pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class Matrix {
    private:
        int elements[25], filled, M, N, size;
        int el(int, int);
    public:
        // constructors
        Matrix();
        Matrix(int, int);
        
        // getters and setters
        int rows();
        int columns();
        int get_filled();
        int get_size();
        int element(int, int);
        // Matrix row(int);
        // Matrix col(int);

        // testing functions
        void test();
        
        // destructor
        ~Matrix();
        
        // overloaded operators
        friend Matrix operator +(Matrix first, Matrix second);
        friend Matrix operator -(Matrix first, Matrix second);
        friend Matrix operator *(Matrix first, Matrix second);
        friend Matrix operator *(int first, Matrix second);
        friend Matrix operator *(Matrix first, int second);
        friend Matrix operator *(double first, Matrix second);
        friend Matrix operator *(Matrix first, double second);
        friend istream& operator >>(istream &ins, Matrix &matrix);
        friend ostream& operator <<(ostream &ofs, Matrix matrix);
};

Matrix operator +(Matrix first, Matrix second);
Matrix operator -(Matrix first, Matrix second);
Matrix operator *(Matrix first, Matrix second);
Matrix operator *(int first, Matrix second);
Matrix operator *(Matrix first, int second);
Matrix operator *(double first, Matrix second);
Matrix operator *(Matrix first, double second);
istream& operator >>(istream &ins, Matrix &matrix);
ostream& operator <<(ostream &ofs, Matrix matrix);