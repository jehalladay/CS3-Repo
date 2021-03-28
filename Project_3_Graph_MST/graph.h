#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MaxVertices = 26;
const int MaxEdges = (MaxVertices*(MaxVertices - 1) / 2);

struct edge {
    char to;
    char from;
    int weight;
};

enum color {
    White,
    Gray,
    Black
};

class Graph {
    private:
        char start;
        int degree;
        int edges;
        int adjacency_matrix[MaxVertices][MaxVertices];
        color colors[MaxVertices];
        edge edge_list[MaxEdges];

    public:
        Graph(int number_of_vertices, char start_position);
        Graph();

        void add_edge(char to, char from, int weight);
        void print_edges(ostream &ofs);
        int get_edges();
        int get_degree();
        int total_weight();

        Graph MST(char first);

        // overloaded operators
        friend istream& operator >>(istream &ins, Graph &graph);
        friend ostream& operator <<(ostream &ofs, Graph &graph);
        
};


struct element {
    int priority;
    char vertex;
    element *link;
    edge data;
};


class Queue {
    private:
        element *head, *tail;
        int _length;
    public:
        Queue();

        int length();
        bool empty();
        void enQueue(edge e);
        edge deQueue();
};
