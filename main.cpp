#include "graph.h"

int main(){

    string file_name = "graph3.txt";
    int vertex;
    int** arr = read_adjacency_list(file_name, vertex);
    print_adjacency_maxtrix(arr, vertex);

    int colorArray[vertex];
    cout << is_bigraph(arr, vertex, 0, colorArray) << endl;
    cout << is_complete_bigraph(arr, vertex, colorArray);

    delete[] arr;
}