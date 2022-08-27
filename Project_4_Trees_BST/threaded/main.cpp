#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "bst.h"

using namespace std;

void read_file(string source, Tree &T);

int main() {
    string source = "in.dat";
    Tree t;
    ofstream out("out.dat");

    read_file(source, t);

    t.inorder(out);


    return 0;
}


void read_file(string source, Tree &tree) {
    ifstream input_file(source);
    int data = -1;

    while(!input_file.eof()) { 
        input_file >> data;
        if(data != -1) {
            tree.insert(data);
        }
        data = -1;
    }
}