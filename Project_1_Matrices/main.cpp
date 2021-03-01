#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "matrix.h"

using namespace std;


void readFile(string source, Matrix &A, Matrix &B);
void writeToFile(ostream &out, Matrix &A);

int main() {
    string source = "in.dat";
    ofstream out("out.dat");
    Matrix A, B, C;

    // 1) Read in Matrix A and B
    readFile(source, A, B);

    // 2) Print each matrix to the output file
    out << "Matrix A: " << endl;
    writeToFile(out, A);
    out << endl << "Matrix B: " << endl;
    writeToFile(out, B);

    // 3) Add A and B, and print the resulting matrix C
    out << endl << "Matrix C = A + B: " << endl;
    C = A + B;
    writeToFile(out, C);

    // 4) Find A - B and print the reulting matrix C
    out << endl << "Matrix C = A - B: " << endl;
    C = A - B;
    writeToFile(out, C);


    // 5) Find B - A and print the resulting matrix C
    out << endl << "Matrix C = B - A: " << endl;
    C = B - A;
    writeToFile(out, C);

    // 6) Find the matrix C = 3 * A and print the result
    out << endl << "Matrix C = 3 * A: " << endl;
    C = 3 * A;
    writeToFile(out, C);
    

    // 7) Find A * B and print the resulting matrix C
    out << endl << "Matrix C = A * B: " << endl;
    C = A * B;
    writeToFile(out, C);

    // 8) Find B * A and print the resulting matrix C
    out << endl << "Matrix C = B * A: " << endl;
    C = B * A;
    writeToFile(out, C);

    return 0;
}


void readFile(string source, Matrix &A, Matrix &B) {
    ifstream input_file(source);
    int M = 0, N = 0;
    
    input_file >> M >> N;

    Matrix a(M, N);
    input_file >> a;
    M = 0;
    N = 0;

    input_file >> M >> N;

    Matrix b(M, N);
    input_file >> b;
    A = a;
    B = b;
}


void writeToFile(ostream &ofs, Matrix &A) {
    ofs << A;
}
