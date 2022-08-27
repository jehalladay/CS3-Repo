#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "bst.h"

using namespace std;

const int init_data = -1;


Tree::Tree() {
    root = new Node;
    root->data = init_data;
    root->threaded = false;
    root->left = NULL;
    root->right = NULL;
    
}

bool Tree::empty() {
    return root->data == init_data;
}

void Tree::insert(int data) {
    Node *c, *new_node, *parent;

    if(!empty()) {
        new_node = new Node;
        new_node->data = data;
        new_node->left = NULL;

        parent = NULL;
        c = root;

        while(c != NULL) {
            parent = c;
            if(new_node->data < c->data) {
                c = c->left;
            } else {
                if(!c->threaded) {
                    c = c->right;
                } else {
                    c = NULL;
                }
            }
        }
        
        if(new_node->data < parent->data) {
            new_node->threaded = true;
            new_node->right = parent;
            parent->left = new_node;
        } else {
            new_node->threaded = parent->threaded;
            new_node->right = parent->right;
            parent->threaded = false;
            parent->right = new_node;
        }


    } else {
        root->data = data;
    }
}

void Tree::inorder(ostream &out) {
    Node *c;
    bool done = false;
    if(!empty()) {
        c = root;
        out << "In-Order Traversal:\t";

        while(c != NULL) {
            while(c->left != NULL) {
                c = c->left;
            }

            done = false;

            while(!done) {
                out << c->data << '\t';
                if(c->threaded) {
                    c = c->right;
                } else {
                    c = c->right;
                    done = true; 
                }
            }


        }
        
        out << endl;
    }
}


istream& operator >>(istream &ins, Tree &tree) {
    int data;

    ins >> data;
    tree.insert(data);


    return ins;
}
