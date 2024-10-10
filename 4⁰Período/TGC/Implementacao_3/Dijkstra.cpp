
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
    cout << "Matriz de adjacencia de um grafo de " << adj_matrix.size()
         << " vértices: " << endl;
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
void Dijkstra(Graph *g, int v) {
  int n = g->adj_matrix.size();
  vector<int> dist_array(n, INT_MAX);
  vector<bool> visited(n, false);
  vector<int> prev(n, -1);

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  dist_array[v] = 0;
  pq.push({0, v});

  while (pq.empty() == false) {
    int path_vertex = pq.top().second;
    pq.pop();
    if (visited[path_vertex] == true)
      continue;
    visited[path_vertex] = true;

    for (int i = 0; i < n; i++) {
      if (g->adj_matrix[path_vertex][i] != 0 && visited[i] == false) {
        int min_dist = dist_array[path_vertex] + g->adj_matrix[path_vertex][i];
        if (dist_array[i] > min_dist) {
          dist_array[i] = min_dist;
          prev[i] = path_vertex;
          pq.push({min_dist, i});
        }
      }
    }
  }
  cout << "Distâncias do nó de origem " << v << ":" << endl;
  for (int i = 0; i < n; i++) {
    cout << "Distância até o nó " << i << " = " << dist_array[i] << endl;

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
  Dijkstra(g, 0);

  delete (g);
}
