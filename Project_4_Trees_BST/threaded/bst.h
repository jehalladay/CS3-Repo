#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct Node {
    int data;
    bool threaded;
    Node *left, *right;
};

class Tree {
    private:
        Node *root;
        
    public:
        Tree();

        bool empty();
        void insert(int data);
        void inorder(ostream &out);

        friend istream& operator >>(istream &ins, Tree &tree);
};
