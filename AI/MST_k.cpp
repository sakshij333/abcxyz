#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;

    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

class Graph {
    int V;
    vector<Edge> edges;

public:
    Graph(int v) : V(v) {}

    void addEdge(int src, int dest, int weight) {
        edges.push_back(Edge(src, dest, weight));
    }

    vector<Edge> kruskalMST() {
        // Sort edges in ascending order of their weights
        sort(edges.begin(), edges.end(), compareEdges);

        vector<Edge> mst;
        vector<int> parent(V);

        // Initialize parent array for union-find
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        int edgeCount = 0;
        int index = 0;

        while (edgeCount < V - 1 && index < edges.size()) {
            Edge nextEdge = edges[index++];
            int x = find(parent, nextEdge.src);
            int y = find(parent, nextEdge.dest);

            // Add the edge to MST if it does not form a cycle
            if (x != y) {
                mst.push_back(nextEdge);
                unionSets(parent, x, y);
                edgeCount++;
            }
        }

        return mst;
    }

private:
    int find(vector<int>& parent, int i) {
        if (parent[i] != i) {
            parent[i] = find(parent, parent[i]);
        }
        return parent[i];
    }

    void unionSets(vector<int>& parent, int x, int y) {
        parent[x] = y;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph graph(V);

    cout << "Enter the source, destination, and weight of each edge:" << endl;
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph.addEdge(src, dest, weight);
    }

    vector<Edge> mst = graph.kruskalMST();

    cout << "Minimum Spanning Tree Edges:" << endl;
    for (const auto& edge : mst) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }

    return 0;
}


output:
Enter the number of vertices: 4
Enter the number of edges: 5
Enter the source, destination, and weight of each edge:
0 1 1
0 2 3
0 3 2
1 2 2
2 3 4
