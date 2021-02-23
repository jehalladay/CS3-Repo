#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "matrix.h"

using namespace std;

Matrix::Matrix() {
    M = 1;
    N = 3;
    size = 3;
    filled = 0;
}


Matrix::Matrix(int rows, int columns) {
    if(rows > 0 && columns > 0) {
        M = rows;
        N = columns;
        size = M * N;
        filled = 0;
    } else {
        cout << "Cannot set number of rows/columns to 0" << endl;
        throw;
    }
}

Matrix::~Matrix() {
    delete[] elements;
}


int Matrix::el(int row, int column) {
    return elements[row*N+column];
}


int Matrix::element(int row, int column) {
    if(row > M || column > N || row <= 0 || column <= 0) {
        cout << "Cannot specify row/column larger than number of rows/columns or less than or equal to 0" << endl;
        throw;
    }
    return el(row-1, column-1);
}



void Matrix::test() {
    cout << "Hello Matrix" << endl;
}

int Matrix::rows() {
    return M;
}

int Matrix::columns() {
    return N;
}

int Matrix::get_filled() {
    return filled;
}

int Matrix::get_size() {
    return size;
}

Matrix operator +(Matrix first, Matrix second) {
    Matrix newMatrix(first.M, first.N);

    if(first.M != second.M || first.N != second.N) {
        cout << "Cannot perform addition with a "
             << first.M << "X" << first.N << " and a " 
             << second.M << "X" << second.N << " Matrix" << endl;
        throw;
    }

    for(int i = 0; i < first.size; i++) {
        newMatrix.elements[i] = first.elements[i] + second.elements[i];
    }

    newMatrix.filled = newMatrix.size;

    return newMatrix;
}

Matrix operator -(Matrix first, Matrix second) {
    Matrix newMatrix(first.M, first.N);

    if(first.M != second.M || first.N != second.N) {
        cout << "Cannot perform subtraction with a "
             << first.M << "X" << first.N << " and a " 
             << second.M << "X" << second.N << " Matrix" << endl;
        throw;
    }

    for(int i = 0; i < first.size; i++) {
        newMatrix.elements[i] = first.elements[i] - second.elements[i];
    }

    newMatrix.filled = newMatrix.size;

    return newMatrix;
}

Matrix operator *(Matrix first, Matrix second) {
    int M = first.M, N = second.N, current = 0, sum = 0, i = 0, j = 0, k = 0;
    Matrix newMatrix(M, N);

    if(first.N != second.M) {
        cout << "Cannot multiply two matrices MxN and PxQ if N != P" << endl;
        throw;
    }

    for(int e = 0; e < newMatrix.size; e++) {
        i = e / N;
        j = e % N;

        for(k = 0; k < first.N; k++) {
            sum += first.el(i, k) * second.el(k, j);
        }

        newMatrix.elements[e] = sum;
        sum = 0;
    }

    return newMatrix;
}


Matrix operator *(int first, Matrix second) {
    Matrix newMatrix(second.M, second.N);
    
    for(int i = 0; i < second.size; i++) {
        newMatrix.elements[i] = first * second.elements[i];
    }

    newMatrix.filled = newMatrix.size;

    return newMatrix;
}


Matrix operator *(Matrix first, int second) {
    Matrix newMatrix(first.M, first.N);
    
    for(int i = 0; i < first.size; i++) {
        newMatrix.elements[i] = second * first.elements[i];
    }

    newMatrix.filled = newMatrix.size;

    return newMatrix;
}

Matrix operator *(double first, Matrix second) {
    Matrix newMatrix(second.M, second.N);
    
    for(int i = 0; i < second.size; i++) {
        newMatrix.elements[i] = first * second.elements[i];
    }

    newMatrix.filled = newMatrix.size;

    return newMatrix;
}


Matrix operator *(Matrix first, double second) {
    Matrix newMatrix(first.M, first.N);
    
    for(int i = 0; i < first.size; i++) {
        newMatrix.elements[i] = second * first.elements[i];
    }

    newMatrix.filled = newMatrix.size;

    return newMatrix;
}


istream& operator >>(istream &ins, Matrix &matrix) {
    int temp, size = matrix.size;

    if(matrix.filled < size) {
        while(matrix.filled < size) {
            ins >> temp;
            matrix.elements[matrix.filled] = temp;
            matrix.filled++;
        }
        
    } else {
        cout << "Cannot fill a packed matrix" << endl;
        throw;
    }

    return ins;
}


ostream& operator <<(ostream &ofs, Matrix matrix) {
    int size = matrix.size, columns = matrix.N;

    if(matrix.filled != size) {
        cout << "cannot send out elements of an empty matrix" << endl;
    }

    for(int i = 0; i < size; i++) {
        ofs << matrix.elements[i];

        if((i+1)%columns == 0) {
            ofs << endl;
        } else {
            ofs << "\t";
        }
    }

    return ofs;
}
