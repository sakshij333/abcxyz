#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii>> Graph;

vector<int> primMST(const Graph& graph, int startVertex) {
    int V = graph.size();

    vector<int> parent(V, -1);      // Store the MST edges
    vector<int> key(V, INT_MAX);    // Store the minimum edge weights
    vector<bool> inMST(V, false);   // Track whether a vertex is included in MST

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push(make_pair(0, startVertex));
    key[startVertex] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!inMST[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    return parent;
}

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
        graph[src].push_back(make_pair(dest, weight));
        graph[dest].push_back(make_pair(src, weight));
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    vector<int> parent = primMST(graph, startVertex);

    cout << "Minimum Spanning Tree Edges:" << endl;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << endl;
    }

    return 0;
}


output:

Enter the number of vertices: 5
Enter the number of edges: 7
Enter the source, destination, and weight of each edge:
0 1 2
0 2 3
1 2 4
1 3 1
1 4 2
2 3 3
3 4 5
Enter the starting vertex: 0


output:
Enter the number of vertices: 4
Enter the number of edges: 5
Enter the source, destination, and weight of each edge:
0 1 1
0 2 3
1 2 2
1 3 4
2 3 5
Enter the starting vertex: 0
