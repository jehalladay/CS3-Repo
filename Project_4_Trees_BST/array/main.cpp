#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int Maxtree = 100;


void read_file(string, node*);
void print(string);

void create_tree(node*&);
bool empty_tree(node*);
void insert_node(node*, int);
void search_tree(node*, node*&, node*&, int);


int main() {



    return 0;
}


void print(bool s[Maxtree], ofstream &outf) {
    int i;

    for(i='A'; i <= 'Z'; i++) {
        if(s[i]) {
            outf << setw(2) << (char)i;
        } else {
            outf << setw(2) << " ";
        }
    }

    outf << endl << endl;
}
