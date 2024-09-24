#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to generate all subgraphs for a subset of vertices
void generateSubgraphsForVertices(const vector<int>& vertices, int& subgraphCount) {
    int numVertices = vertices.size();
    int numEdges = numVertices * (numVertices - 1) / 2;

    // Generate all possible edges for this subset of vertices
    vector<pair<int, int>> edges;
    for (int i = 0; i < numVertices; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            edges.push_back({vertices[i], vertices[j]});
        }
    }

    // There are 2^numEdges subgraphs for this subset of vertices
    int totalSubgraphs = 1 << numEdges;

    // Iterate through each possible subgraph
    for (int i = 0; i < totalSubgraphs; i++) {
        // Increment the subgraph count
        subgraphCount++;
        cout << "Subgrafo " << subgraphCount << ": Vertices {";
        for (int v : vertices) {
            cout << v << " ";
            
        }

        cout << "} | Arestas: ";

        // Check which edges are included in this subgraph
        for (int j = 0; j < numEdges; j++) {
            if (i & (1 << j)) {
                cout << "{" << edges[j].first << ", " << edges[j].second << "} ";
            }
        }

        cout << endl;
    }
}
// Function to generate all combinations of vertices
void generateSubgraphs(int n) {
    // There are 2^n possible subsets of vertices (excluding the empty set)
    int totalVertexSubsets = 1 << n;

    // Initialize subgraph counter
    int subgraphCount = 0;

    // Iterate through each possible subset of vertices
    for (int i = 1; i < totalVertexSubsets; i++) {
        vector<int> vertices;

        // Check which vertices are included in this subset
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                vertices.push_back(j);
            }
        }

        // Generate all subgraphs for this subset of vertices
        generateSubgraphsForVertices(vertices, subgraphCount);
    }
}

int main() {
    int n;

    // Input the number of vertices in the complete graph
    cout << "Insira o numero total de vertices: ";
    cin >> n;

    // Generate all subgraphs
    generateSubgraphs(n);

    return 0;
}
