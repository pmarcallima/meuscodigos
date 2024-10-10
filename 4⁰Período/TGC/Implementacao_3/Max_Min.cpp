#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Grafo utilizando matriz de adjacência
class Graph {

public:
  vector<vector<int>> adj_matrix;
  Graph(int n) { adj_matrix = vector<vector<int>>(n, vector<int>(n, 0)); }
  void add_edge(int u, int v, int p) { adj_matrix[u][v] = p; }

  // Método para imprimir a matriz de adjacência do grafo
  void print() {
    cout << "Matriz de adjacência de um grafo de " << adj_matrix.size()
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
// @param vector<int> &prev vetor de antecessores
// @param int v vértice para começar a recursão
void print_path(const vector<int> &prev, int v) {
  if (prev[v] == -1) {
    cout << v; 
    return;
  }
  print_path(prev, prev[v]); 
  cout << " -> " << v;       
}

// Algoritmo Max_Min
// @param Graph *g grafo criado na função main
// @param int v vértice de início para o algoritmo
void Max_Min(Graph *g, int v) {
  int n = g->adj_matrix.size(); 

  //Array da menor aresta em um caminho
  vector<int> min_path_edge(n, INT_MIN);

  //Array de antecessores
  vector<int> prev(n, -1);

  //Array de visitados
  vector<bool> visited(n, false);

  // Fila de prioridade mínima 
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  // Inicializa o vértice de origem
  min_path_edge[v] = INT_MAX;
  pq.push({INT_MAX, v});

  // Processa os vértices enquanto a fila de prioridade não estiver vazia
  while (!pq.empty()) {
    int max_min_vertex = pq.top().second;
    pq.pop();

    // Se o vértice já foi visitado, ignora
    if (visited[max_min_vertex] == true)
      continue;
    visited[max_min_vertex] = true;

    // Itera sobre todos os vizinhos do vértice atual
    for (int x = 0; x < n; x++) {
      if (g->adj_matrix[max_min_vertex][x] != 0 && visited[x] == false) {
        // Calcula a nova menor aresta no caminho
        int new_min_edge = min(min_path_edge[max_min_vertex],
                               g->adj_matrix[max_min_vertex][x]);

        // Se encontrar uma nova maior "menor aresta" no caminho para x
        if (min_path_edge[x] < new_min_edge) {
          min_path_edge[x] = new_min_edge;
          prev[x] = max_min_vertex;
          pq.push(
              {new_min_edge, x}); // Adiciona x à fila com a nova menor aresta
        }
      }
    }
  }

  // Imprime os resultados
  cout << "max_min para cada vértice a partir de " << v << ":" << endl;
  for (int i = 0; i < n; i++) {
    cout << "Vértice " << i << " = " << min_path_edge[i] << endl;

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

  Max_Min(g, 0);

  delete g;
}
