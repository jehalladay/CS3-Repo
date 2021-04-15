#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "bst.h"

using namespace std;

const int init_data = -1;


Tree::Tree() {
    root = NULL;
    // root->data = init_data;
    // root->left = NULL;
    // root->right = NULL;
}

bool Tree::empty() {
    return root == NULL;
}

void Tree::insert(int data) {
    Node *c, *new_node;
    new_node = new Node;
    new_node->data = data;
    if(!empty) {
        
    }

    
}

void Tree::inorder(ostream &out) {

}

istream& operator >>(istream &ins, Tree &tree) {
    int data;

    ins >> data;
    tree.insert(data);


    return ins;
}
