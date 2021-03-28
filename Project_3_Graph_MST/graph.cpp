#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "graph.h"

using namespace std;


Graph::Graph() {
    degree = 0;
    edges = 0;
    start = 'A';
}


Graph::Graph(int number_of_vertices, char start_position) {
    degree = number_of_vertices;
    edges = 0;
    start = start_position;
    char end = (start + degree - 1);

    for(int i = 0; i < degree; i++) {
        colors[i] = White;

        for(int j = 0; j < degree; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }

    // cout << "Degree: " << degree 
    //      << " From: " << start 
    //      << " To: "   << end << endl;
}


void Graph::add_edge(char to, char from, int weight) {
    char end = start + degree - 1;
    edge e;

    if(start <= from && end >= from && start <= to && end >= to) {
        if(adjacency_matrix[from - start][to - start] == 0 && adjacency_matrix[to - start][from - start] == 0) {

            adjacency_matrix[from - start][to - start] = weight;
            adjacency_matrix[to - start][from - start] = weight;

            e.to = to;
            e.from = from;
            e.weight = weight;
            
            edge_list[edges] = e;
            edges++;
        } else {
            cout << "Cannot add edge where edge already exists" << endl;
            throw;
        }
    } else {
        cout << "Cannot add edge to vertice that does not exist" << endl;
        throw;
    }
}


void Graph::print_edges(ostream &ofs) {
    ofs << "To:\tFrom:\tWeight:" << endl;
    for(int i = 0; i < edges; i++) {
        ofs << edge_list[i].to     << '\t' 
            << edge_list[i].from   << "\t\t"
            << edge_list[i].weight << endl;
    }
}


Graph Graph::MST(char first) {
    int V_1 = first - start, V_2;
    Graph mst(degree, start);
    Queue Q;
    edge e;

    colors[V_1] = Gray;

    e.to = first;
    e.from = ' ';
    e.weight = -1;
    Q.enQueue(e);

    while(!Q.empty()) {
        e = Q.deQueue();
        V_1 = e.to - start;

        // cout << "to: " << e.to << " from: " << e.from << " weight: " << e.weight << endl;
        if(colors[V_1] != Black) {
            if(e.weight != -1) {
                mst.add_edge(e.to, e.from, e.weight);
            }

            for(V_2 = 0; V_2 < degree; V_2++) {
                if(adjacency_matrix[V_2][V_1] != 0 && colors[V_2] != Black) {
                    colors[V_2] = Gray;
                    e.to = V_2 + start;
                    e.from = V_1 + start;
                    e.weight = adjacency_matrix[V_2][V_1];
                    Q.enQueue(e);
                }
            }
        }

        colors[V_1] = Black;
    }

    // reset colors to white
    for(int i = 0; i < degree; i++) {
        colors[i] = White;
    }

    return mst;
}


int Graph::get_edges() {
    return edges;
}


int Graph::get_degree() {
    return degree;
}


int Graph::total_weight() {
    int sum = 0;

    for(int i = 0; i < edges; i++) {
        sum += edge_list[i].weight;
    }

    return sum;
}


istream& operator >>(istream &ins, Graph &graph) {
    char V_1 = ' ', V_2 = ' ';
    int weight = 0;

    ins >> V_1 >> V_2 >> weight;

    if(V_1 != ' ' && V_2 != ' ') {
        graph.add_edge(V_1, V_2, weight);
    }

    return ins;
}


ostream& operator <<(ostream &ofs, Graph &graph) {
    int degree = graph.get_degree();
    if(degree == 0) {
        cout << "cannot print graph with degree of 0" << endl;
    }
    // graph.adjacency_matrix[12][12];
    for(int i = -1; i < degree; i++) {
        for(int j = -1; j < degree; j++) {
            // cout << " I: " << i << " J: " << j << endl;
            if(i == -1 && j == -1) {
                ofs << ' ';
            } else if(i == -1 && j != -1) {
                ofs << ' ' << char(j + graph.start);
            } else if(j == -1) {
                ofs << char(i + graph.start) << ' ';
            } else {
                ofs << graph.adjacency_matrix[i][j] << ' '; 
            }
            if(j == degree - 1) {
                ofs << endl;
            }
        }
    }
    ofs << endl;
}



Queue::Queue() {    
    head = new element;
    tail = new element;

    head->link = tail;
    tail->link = NULL;

    head->vertex = ' ';
    tail->vertex = ' ';

    head->priority = 0;
    tail->priority = 9999999;

    _length = 0;
}


int Queue::length() {
    return _length;
}


bool Queue::empty() {
    return head->link == tail;
}


void Queue::enQueue(edge e) {
    element *new_element, *prior, *next;
    bool found = false, keep = true;

    new_element = new element;
    new_element->priority = e.weight;
    new_element->vertex = e.to;
    new_element->data = e;

    next = head->link;
    prior = head;

    // First we make sure the vertext the edge leads 
    // to is not in the queue. if it is in queue
    // delete if priority is lower than new edge
    // else we leave it in there and forget the new edge

    while(next != tail && !found) {
        if(next->vertex == new_element->vertex) {
            found = true;
            if(next->priority > new_element->priority) {
                prior->link = next->link;
                _length--;
                delete next;
            } else {
                // if priority of existing edge 
                // in queue is higher than new one
                // we do not keep the new edge
                keep = false;
            }
        }

        if(!found) {
            prior = next;
            next = next->link;
        }
    }

    if(keep) {
        next = head->link;
        prior = head;

        while(next != tail && next->priority <= new_element->priority) {
            prior = next;
            next = next->link;
        }

        prior->link = new_element;
        new_element->link = next;
        _length++;
    }
}


edge Queue::deQueue() {
    element *c;
    edge e;

    if(empty()) {
        cout << "Cannot dequeue from an empty queue" << endl;
        throw;
    }

    c = head->link;
    e = c->data;
    head->link = c->link;
    delete c;

    return e;
}