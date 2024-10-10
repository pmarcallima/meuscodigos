
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Grafo com matriz de adjacência
class Graph {

public:
  vector<vector<int>> adj_matrix;

  Graph(int n) { adj_matrix = vector<vector<int>>(n, vector<int>(n, 0)); }
  void add_edge(int u, int v, int p) { adj_matrix[u][v] = p; }
  // Imprimir a matriz de adjacência
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

// Função recursiva para imprimir o caminho percorrido a partir dos antecedentes
//@param vector<int> &prev vetor de antecessores
//@param int v vértice para começar a recursão
void print_path(const vector<int> &prev, int v) {
  if (prev[v] == -1) {
    cout << v;
    return;
  }
  print_path(prev, prev[v]);
  cout << " -> " << v;
}
// Algoritmo de Dijkstra
//@param Graph *g grafo criado na função main
//@param int v vértice em que se começa o dijkstra
void Dijkstra(Graph *g, int v) {
  int n = g->adj_matrix.size();
  // Array de distâncias
  vector<int> dist_array(n, INT_MAX);
  // Array de visitados
  vector<bool> visited(n, false);
  // Array de antecessores
  vector<int> prev(n, -1);

  // Fila de prioridade mínima
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  // Inicialização do vértice de origem 
  dist_array[v] = 0;
  pq.push({0, v});

  // Processa os vértices enquanto a fila de prioridade não estiver vazia
  while (pq.empty() == false) {
    int path_vertex = pq.top().second;
    pq.pop();

    // Se o vértice já foi visitado, ignora
    if (visited[path_vertex] == true)
      continue;
    visited[path_vertex] = true;

    // Itera sobre todos os vizinhos do vértice atual
    for (int i = 0; i < n; i++) {
      if (g->adj_matrix[path_vertex][i] != 0 && visited[i] == false) {
        int min_dist =
            dist_array[path_vertex] +
            g->adj_matrix[path_vertex][i]; // Calculo da distância nova
        
        // Se encontrar um novo menor caminho no caminho para i
        if (dist_array[i] > min_dist) {
          dist_array[i] = min_dist;
          prev[i] = path_vertex;
          pq.push({min_dist, i}); // Adiciona i à fila com a nova menor aresta
        }
      }
    }
  }
  // Imprimindo os resultados
  cout << "Distâncias do nó de origem " << v << ":" << endl;
  for (int i = 0; i < n; i++) {
    cout << "Distância até o nó " << i << " = " << dist_array[i] << endl;

    // Imprime o caminho feito
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
