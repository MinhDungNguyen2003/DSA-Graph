#include "graph.h"

int main(){

    int vertex;
    string file_name = "graph3.txt";
    int** arr = read_adjacency_list_ungraph(file_name, vertex);
    int colorArray[vertex];
    int visited[vertex] = {0};
    int ntree = 0;
    
    
    print_adjacency_maxtrix(arr, vertex);
    cout << number_connect_components(arr, vertex, ntree) << endl;
    cout << ntree << endl;
    delete[] arr;

    vector<int>* adj; 
    string file_name1 = "graph4.txt";
    read_adjacency_maxtrix(file_name1, adj, vertex);
    cout << "Cut vertices are: ";
    AP(adj, vertex);
    findBridges_Tarjan(adj, vertex);

    return 0;
}


