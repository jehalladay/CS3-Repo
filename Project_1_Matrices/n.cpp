#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "matrix.h"

using namespace std;

int main() {
    // ofstream out("out.dat");
    cout << "hello world" << endl;

    Matrix A, B(3, 3);
    cin >> B;

    cout << B.get_filled() << endl;
    cout << B << endl;
    
    A.test();
    return 0;
}