#include "graph.h"

int main(){

    string file_name = "graph3.txt";
    int vertex;
    int** arr = read_adjacency_list(file_name, vertex);
    print_adjacency_maxtrix(arr, vertex);
    cout << is_bigraph_graph(arr, vertex, 0);

    delete[] arr;
}