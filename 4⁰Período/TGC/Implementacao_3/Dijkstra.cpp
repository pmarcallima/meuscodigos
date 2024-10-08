
#include <climits>
#include <iostream>
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
void Dijkstra(Graph *g, int v) {
  int n = g->adj_matrix.size();
  vector<int> dist_array(n, INT_MAX);
  vector<bool> visited(n, false);
  dist_array[v] = 0;
  for (int i = 0; i < n; i++) {
    int min_dist = -1;
    for (int j = 0; j < n; j++) {
      if (visited[j] == false &&
          (min_dist == -1 || dist_array[j] < dist_array[min_dist]))
        min_dist = j;
    }
    visited[min_dist] = true;

    for (int x = 0; x < n; x++) {
      if (g->adj_matrix[min_dist][x] != 0 && visited[x] == false) {
        int new_dist = dist_array[min_dist] + g->adj_matrix[min_dist][x];
        if (dist_array[x] > new_dist) {
          dist_array[x] = new_dist;
        }
      }
    }
  }
  cout << "Distâncias do nó de origem " << v << ":" << endl;
  for (int i = 0; i < n; i++) {
    cout << "Distância até o nó " << i << " = " << dist_array[i] << endl;
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
  Dijkstra(g, 0);

  delete (g);
}
