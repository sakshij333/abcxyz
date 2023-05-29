#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to compare two edges based on their weights (used for sorting)
bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

// Find operation for union-find
int find(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union operation for union-find
void unionSets(vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to find the Minimum Spanning Tree using Kruskal's algorithm
vector<Edge> kruskalMST(vector<Edge>& edges, int V) {
    // Sort the edges in non-decreasing order of their weights
    sort(edges.begin(), edges.end(), compareEdges);

    vector<Edge> result; // Stores the edges of the MST
    vector<Subset> subsets(V);

    // Initialize subsets with each vertex as a separate subset
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int numEdges = 0;
    int index = 0;

    // Build the MST by considering edges in the sorted order
    while (numEdges < V - 1 && index < edges.size()) {
        Edge nextEdge = edges[index++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // Include the edge in the MST if it doesn't form a cycle
        if (x != y) {
            result.push_back(nextEdge);
            unionSets(subsets, x, y);
            numEdges++;
        }
    }

    return result;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter the source, destination, and weight of each edge:" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    vector<Edge> mst = kruskalMST(edges, V);

    cout << "Minimum Spanning Tree Edges:" << endl;
    for (const auto& edge : mst) {
        cout << edge.src << " -- " << edge.dest << "  Weight: " << edge.weight << endl;
    }

    return 0;
}







output:
Enter the number of vertices: 6
Enter the number of edges: 9
Enter the source, destination, and weight of each edge:
0 1 4
0 2 2
1 2 1
1 3 5
2 3 8
2 4 10
3 4 2
3 5 6
4 5 3


output:
Enter the number of vertices: 4
Enter the number of edges: 5
Enter the source, destination, and weight of each edge:
0 1 1
0 2 3
1 2 2
1 3 4
2 3 5
