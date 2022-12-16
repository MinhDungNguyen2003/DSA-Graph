#include "graph.h"

void DFS(int** arr, int vertex, int visited[], int src){

    visited[src] = 1;
    for(int u = 0; u < vertex; u++){
        if(arr[src][u] && visited[u] == 0){
            DFS(arr, vertex, visited, u);
        }
    }

}

vector<int> BFS(int** arr, int vertex, int visited[], int src){

    vector<int> c;
    queue<int> q;
    q.push(src);
    c.push_back(src);

    visited[src] = 1;
    while(!q.empty()){

        int u = q.front();
        q.pop();
        
        for(int v = 0; v < vertex; v++){
            if (u != v){
                if(arr[u][v] && !visited[v]){
                    visited[v] = 1;
                    q.push(v);
                    c.push_back(v);
                }
            }
        }
        
    }
    
    return c;

}


void print_adjacency_maxtrix(int** arr, int vertex){
    
    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void read_adjacency_maxtrix(string file_name){

    fstream fin;
    fin.open(file_name, ios::in);
    string get;
    int i = 0;
    fin >> get;
    int vertex = stoi(get);
    while(fin >> get){
        if(get == "0"){
            i++;
        }
        if (get == "1"){
            cout << i << " ";
            i++;
        }
        if(i == vertex){
            cout << endl;
            i = 0;
        }

    }
    fin.close();

}

int** read_adjacency_list_digraph(string file_name, int &vertex){

    fstream fin(file_name, ios::in);
    string get;
    getline(fin, get);
    vertex = stoi(get);

    int** arr = new int*[vertex];
    for(int i = 0; i < vertex; i++){
        arr[i] = new int [vertex];
    }

    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            arr[i][j] = 0;
        }
    }
    
    int i = 0;
    while(getline(fin, get)){
        stringstream s(get);
        string word;
        while(s >> word){
            arr[i][stoi(word)] = 1;
        }
        i++;
    }

    return arr;
}

int** read_adjacency_list_ungraph(string file_name, int &vertex){

    fstream fin(file_name, ios::in);
    string get;
    getline(fin, get);
    vertex = stoi(get);

    int** arr = new int*[vertex];
    for(int i = 0; i < vertex; i++){
        arr[i] = new int [vertex];
    }

    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            arr[i][j] = 0;
        }
    }
    
    int i = 0;
    while(getline(fin, get)){
        stringstream s(get);
        string word;
        while(s >> word){
            arr[i][stoi(word)] = 1;
            arr[stoi(word)][i] = 1;
        }
        i++;
    }

    return arr;
}

bool is_digraph(int** a, int vertex){

    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            if (a[i][j] != a[j][i]){
                return 1;
            }
        }
    }
    return 0;
}

int numberE_numberV(int** arr, int vertex){

    int e = 0;
    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            if(arr[i][j] == 1){
                e += 1;
            }
        }
    }
    
    if(is_digraph(arr, vertex)){
        return e;
    }
   
    return e / 2;
}

void degree_digraph(int** arr, int vertex){

    int i = 0;
    int degree_in = 0;
    int degree_out = 0;

    while (i < vertex){
        for(int j = 0; j < vertex; j++){
            if(arr[i][j] == 1){
                degree_out += 1;
            }
        }

        for(int j = 0; j < vertex; j++){
            if(arr[j][i] == 1){
                degree_in += 1;
            }
        }

        cout << "Vertex " << i << ": " << "In-degree: " << degree_in << " --- " << "Out-degree: " << degree_out << endl; 
        i++;
        degree_in = degree_out = 0;
    }

}

void degree_undigraph(int** arr, int vertex){

    int degree = 0; 
    int i = 0;

    while(i < vertex){
        for(int j = 0; j < vertex; j++){
            if(arr[i][j] == 1){
                degree += 1;
            }
        }
        cout << "Deg(" << i << ") = " << degree;
        degree = 0; 
        i++;
    }

}

void list_isolated_vertices(int** arr, int vertex){

    int i = 0;
    int connect = 0;
    cout << "List isolated vertices: ";  
    while(i < vertex){
        for(int j = 0; j < vertex; j++){
            if(arr[i][j] == 1){
                connect += 1;
            }

            if(arr[j][i] == 1){
                connect += 1;
            }
        }

        if (connect == 0){
            cout << i << " ";
        }
        i++;
        connect = 0;
    }

}

bool is_complete_graph(int** arr, int vertex){

    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            if(i != j){
                if(arr[i][j] == 0){
                    return 0;
                }
                if(arr[i][j] != arr[j][i]){
                    return 0;
                }
            }
        }
    }

    return 1;
}

bool is_circular_graph(int** arr, int vertex){

    if (vertex < 3){
        return 0;
    }

    for(int i = 0; i < vertex - 1; i++){
        if(arr[i][i + 1] == 0){
            return 0;
        }
        else{
            if (arr[i][i + 1] != arr[i + 1][i]){
                return 0;
            }
        }
    }
        
    if(arr[0][vertex - 1] == 0){
        return 0;
    }
    else{
        if(arr[0][vertex - 1] != arr[vertex - 1][0]){
            return 0;
        }
    }
            
    return 1;

}

bool is_bigraph(int** arr, int vertex, int src, int colorArr[]){

    //create array contain color vertex
    colorArr[vertex];
    for(int i = 0; i < vertex; i++){
        colorArr[i] = -1;
    }

    //asign first color to source
    colorArr[src] = 1;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        // Return false if there is a self-loop
        if(arr[u][u] == 1){
            return 0;
        }

        for(int v = 0; v < vertex; v++){
            if(arr[u][v] && colorArr[v] == -1){
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }
            else if (arr[u][v] && colorArr[v] == colorArr[u]){
                return 0;
            }
        }
    }
    return 1;

}

bool is_complete_bigraph(int** arr, int vertex, int src, int colorArray[]){

    if(!is_bigraph(arr, vertex, 0, colorArray)){
        return 0;
    }

    for(int u = 0; u < vertex; u++){
        for(int v = 0; v < vertex; v++){
            if(u != v){
                if(colorArray[u] != colorArray[v]){
                    if(arr[u][v] == 0){
                        return 0;
                    }
                }
            }
        }
    }

    return 1;
}

bool isCycle(int** arr, bool vis[], int u, int vertex, int parent){

    vis[u] = true;    //mark v as visited
    for (int v = 0; v < vertex; v++) {
        if (arr[u][v]) {
            if (!vis[v]) {     //when the adjacent node v is not visited
                if (isCycle(arr, vis, v, vertex, u)) {
                    return true;
                }
            }
            else if (v != parent) {    //when adjacent vertex is visited but not parent
                return true;    //there is a cycle
            }
        }
    }
    return false;
}

int number_connect_components(int** arr, int vertex, int &ntree){

    int visited[vertex] = {0};
    int cnt = 0;
    for(int i = 0; i < vertex; i++){
        if(!visited[i]){
            vector<int> c;
            c = BFS(arr, vertex, visited, i);
            cnt++;
            
            int** a = new int* [c.size()];
            for(int i = 0; i < c.size(); i++){
                a[i] = new int [c.size()];
            }

            for(int j = 0; j < c.size(); j++){
                for(int k = 0; k < c.size(); k++){
                    a[j][k] = arr[c[j]][c[k]];
                }
            }
            
            bool* vis = new bool [c.size()];
            for(int i = 0; i < c.size(); i++){
                vis[i] = 0;
            }

            if (isCycle(a, vis, 0, c.size(), -1) == 0){
                ntree += 1;
            }

            for(int i = 0; i < c.size(); i++){
                delete[] a[i];
            }
            delete[] a;
            delete[] vis;
        }
    }
    
    return cnt;
}

