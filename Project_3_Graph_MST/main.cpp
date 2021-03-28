#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "graph.h"

using namespace std;

void read_file(string source, Graph &G);

int main() {
    string source = "in.dat";
    Graph G(13, 'A'), MST;
    ofstream out("out.dat");
    

    // 1) Read edges from file into graph

    read_file(source, G);

    // 2) Print the two dimensional adjacency matrix 
    //      using row and column titles

    out << "The Adjacency Matrix of Graph G" << endl << endl;;
    out << G;

    // 3) Use Prim's Algorithm to compute the
    //      Minimum Spanning Tree of Graph G
    
    MST = G.MST('A');

    // 4) Print the list of edges that make up the 
    //      Minimum Spanning Tree for G

    out << "The Minimum Spanning Tree(MST) of G consists of the edges: " << endl << endl;
    MST.print_edges(out);

    // 5) Print the total weight of the Minimum Spanning Tree

    out << endl << "The Total Weight of the MST for G is: " << MST.total_weight() << endl;

    return 0;
}


void read_file(string source, Graph &graph) {
    ifstream input_file(source);

    while(!input_file.eof()) { 
        input_file >> graph;
    }
}