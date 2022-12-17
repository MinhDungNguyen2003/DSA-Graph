#include "graph.h"

int main(){

    int vertex;
    string file_name = "graph2.txt";
    cout << "Maxtrix directed: " << endl;
    int** arr = read_adjacency_list_digraph(file_name, vertex);
    print_adjacency_maxtrix(arr, vertex);

    int ntree = 0;

    vector<int>* adj; 
    string file_name1 = "graph1.txt";
    read_adjacency_maxtrix(file_name1, adj, vertex);
    print_adjacency_list(adj, vertex);
    
    if(is_digraph(arr, vertex)){
        cout << "The graph given is directed graph " << "\n";
        degree_digraph(arr, vertex);
    }
    else{
        cout << "The graph given is undirected graph " << "\n";
        degree_undigraph(arr, vertex);
    }

    cout << "The number of vertex is: " << vertex << endl;
    cout << "The number of edges is: " << numberE_numberV(arr, vertex) << "\n";
    cout << "The number of Connected components: " << number_connect_components(arr, vertex, ntree) << endl;
    cout << "Number of tree in graph is: " << ntree << endl; 
    list_isolated_vertices(arr, vertex);
    cout << endl;

//------------------------------------------------------------------------------

    
    cout << "Matrix undirected: " << endl;
    int** arr1 = read_adjacency_list_ungraph(file_name, vertex);
    print_adjacency_maxtrix(arr1, vertex);
    int colorArray[vertex];
    int visited[vertex] = {0};

    if(is_complete_graph(arr1, vertex)){
        cout << "The graph given is complete graph \n";
    }
    else{
        cout << "The graph given isn't complete graph \n";
    }

    if(is_circular_graph(arr1, vertex)){
        cout << "The graph given is circular graph \n";
    }
    else{
        cout << "The graph given isn't circular graph \n";
    }

    if(is_bigraph(arr1, vertex, 0, colorArray)){
        cout << "The graph given is bigraph \n";
    }
    else{
        cout << "The graph given isn't bigraph \n";
    }

    if(is_complete_bigraph(arr1, vertex, 0, colorArray)){
        cout << "The graph given is complete bigraph \n";
    }
    else{
        cout << "The graph given isn't complete bigraph \n";
    }

    write_adjacency_matrix(arr1, vertex);
    read_adjacency_maxtrix("graph.txt", adj, vertex);

    cout << "Cut vertices are: ";
    AP(adj, vertex);
    findBridges_Tarjan(adj, vertex);

    delete[] arr;
    return 0;
}


