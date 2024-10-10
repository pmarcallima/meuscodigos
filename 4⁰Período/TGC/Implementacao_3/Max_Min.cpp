


#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// Algoritmo de disjkstra

class Graph {

public:
  vector<vector<int>> adj_matrix;

  Graph(int n) { adj_matrix = vector<vector<int>>(n, vector<int>(n, 0)); }
  void add_edge(int u, int v, int p) { adj_matrix[u][v] = p; }
  void print() {
    cout << "Matriz de adjacencia de um grafo de "<< adj_matrix.size() <<" vértices: " << endl;
    int n = adj_matrix.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << adj_matrix[i][j] << " ";
      }
      cout << endl;
    }
  }
};

void print_path(const vector<int> &prev, int v) {
  if (prev[v] == -1) {
    cout << v; 
    return;
  }
  print_path(prev, prev[v]); 
  cout << " -> " << v;       
}

void Max_Min(Graph *g, int v) {
  int n = g->adj_matrix.size();
  vector<int> min_path_edge(n, INT_MIN); 
  vector<int> prev(n, -1);              
  vector<bool> visited(n, false);      

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  min_path_edge[v] = INT_MAX;
  pq.push({INT_MAX, v});

  while (!pq.empty()) {
    int max_min_vertex = pq.top().second;
    pq.pop();

    if (visited[max_min_vertex] == true) continue; 
    visited[max_min_vertex] = true;

    for (int x = 0; x < n; x++) {
      if (g->adj_matrix[max_min_vertex][x] != 0 && visited[x] == false) {
        int new_min_edge = min(min_path_edge[max_min_vertex], g->adj_matrix[max_min_vertex][x]);

        if (min_path_edge[x] < new_min_edge) {
          min_path_edge[x] = new_min_edge;
          prev[x] = max_min_vertex;
          pq.push({new_min_edge, x}); 
        }
      }
    }
  }

  cout << "max_min para cada vértice a partir de " << v << ":" << endl;
  for (int i = 0; i < n; i++) {
    cout << "Vértice " << i << " = " << min_path_edge[i] << endl;
    cout << "Caminho: ";
    print_path(prev, i);  
    cout << endl;
  }
}

int main() {
  Graph *g = new Graph(6);

    g->add_edge(0, 1, 7);
    g->add_edge(0, 2, 9);
    g->add_edge(0, 5, 14);
   g->add_edge(1, 2, 10);
    g->add_edge(1, 3, 15);
    g->add_edge(2, 3, 11);
    g->add_edge(2, 5, 2);
    g->add_edge(3, 4, 6);
    g->add_edge(4, 5, 9);

  g->print();
  Max_Min(g, 0);

  delete (g);
}
