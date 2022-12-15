#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

void print_adjacency_maxtrix(int** arr, int vertex);

void read_adjacency_maxtrix(string file_name);

int** read_adjacency_list(string file_name, int &vertex);

bool is_digraph(int** a, int vertex);

int numberE_numberV(int** arr, int vertex);

void degree_digraph(int** arr, int vertex);

void degree_undigraph(int** arr, int vertex);

void list_isolated_vertices(int** arr, int vertex);

bool is_complete_graph(int** arr, int vertex);

bool is_circular_graph(int** arr, int vertex);

bool is_bigraph_graph(int** arr, int vertex, int src);

bool is_complete_bigraph(int** arr, int vertex);