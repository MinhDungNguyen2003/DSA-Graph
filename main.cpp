#include "graph.h"

int main(){

    string file_name = "graph4.txt";
    int vertex;
    int** arr = read_adjacency_list_ungraph(file_name, vertex);
    print_adjacency_maxtrix(arr, vertex);

    int colorArray[vertex];
    int visited[vertex] = {0};

    cout << number_connect_components(arr, vertex);



    delete[] arr;
}