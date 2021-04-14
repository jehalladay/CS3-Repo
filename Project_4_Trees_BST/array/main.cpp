#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int Maxtree = 100, init_data = -1;


void read_file(string source, int tree[Maxtree]);

void create_tree(int tree[Maxtree]);
bool empty_tree(int tree[Maxtree], int index);
void insert_node(int tree[Maxtree], int data);
void traverse(int tree[Maxtree], ofstream &ofs);
void inorder(int tree[Maxtree], int index, ofstream &ofs);


int main() {
    int tree[Maxtree];
    string source = "in.dat";
    ofstream out("out.dat");

    // initialize the tree array
    create_tree(tree);

    // insert values into tree
    read_file(source, tree);

    // print values accross one row
    traverse(tree, out);

    return 0;
}


void read_file(string source, int tree[Maxtree]) {
    int data = init_data;
    if(empty_tree(tree, 1)) {
        ifstream input_file("in.dat");

        while(!input_file.eof()) {
            input_file >> data;
            if(data != init_data) {
                insert_node(tree, data);
            }
            data = init_data;
        }
    }
}


void create_tree(int tree[Maxtree]) {
    for(int i = 0; i < Maxtree; i++) {
        tree[i] = init_data;
    }
}


bool empty_tree(int tree[Maxtree], int index) {
    return tree[index] == init_data;
}


void insert_node(int tree[Maxtree], int data) {
    int i = 1;

    // search for where to insert

    while(i < Maxtree && tree[i] != init_data) {
        if(data < tree[i]) {
            i *= 2;
        } else {
            i = (i*2)+1;
        }
    }
    
    // update data
    
    if (i < Maxtree) {
        tree[i] = data;
    } else {
        cout << "Tree is not large enough to insert value" << endl;
    }
}


void traverse(int tree[Maxtree], ofstream &ofs) {
    int index = 1;
    if(!empty_tree(tree, index)) {
        ofs << "In-Order Traversal:\t";
        inorder(tree, index, ofs);
        ofs << endl;
    } else {
        cout << "Cannot traverse an empty tree" << endl;
    }
}


void inorder(int tree[Maxtree], int index, ofstream &ofs) {
    if (2*index + 1 < Maxtree) {
        if(tree[2*index] != init_data) {
            inorder(tree, index*2, ofs);
        }

        ofs << tree[index] << '\t';

        if(tree[2*index + 1] != init_data) {
            inorder(tree, index*2 + 1, ofs);
        }
    }
}
