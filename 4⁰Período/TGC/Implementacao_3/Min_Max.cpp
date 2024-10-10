
#include <algorithm>
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

// Algoritmo de Min_Max
//@param Graph *g grafo criado na função main
//@param int v vértice de início para o algoritmo
void Min_Max(Graph *g, int v) {
  int n = g->adj_matrix.size();
  // Array da maior aresta em um caminho
  vector<int> max_path_edge(n, INT_MAX);
  // Array de antecessores
  vector<int> prev(n, -1);
  // Array de visitados
  vector<bool> visited(n, false);

  // Fila de prioridade mínima
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  // Inicialização do vértice de origem
  max_path_edge[v] = INT_MIN;
  pq.push({INT_MIN, v});

  // Processa os vértices enquanto a fila de prioridade não estiver vazia
  while (!pq.empty()) {
    int min_max_vertex = pq.top().second;
    pq.pop();

    // Se o vértice já foi visitado, ignora
    if (visited[min_max_vertex] == true)
      continue;
    visited[min_max_vertex] = true;

    // Itera sobre todos os vizinhos do vértice atual
    for (int x = 0; x < n; x++) {
      if (g->adj_matrix[min_max_vertex][x] != 0 && visited[x] == false) {
        int new_max_edge = max(
            max_path_edge[min_max_vertex],
            g->adj_matrix[min_max_vertex][x]); // Calculo da nova maior aresta

        // Se encontrar uma nova menor "maior aresta" no caminho para x
        if (max_path_edge[x] > new_max_edge) {
          max_path_edge[x] = new_max_edge;
          prev[x] = min_max_vertex;
          pq.push(
              {new_max_edge, x}); // Adiciona x à fila com a nova menor aresta
        }
      }
    }
  }

  // Imprimindo os resultados
  cout << "Min_Max para cada vértice a partir de " << v << ":" << endl;
  for (int i = 0; i < n; i++) {
    cout << "Vértice " << i << " = " << max_path_edge[i] << endl;

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
  Min_Max(g, 0);

  delete g;
}
