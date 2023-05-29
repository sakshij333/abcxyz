#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii; // Pair of vertex and weight

void dijkstra(vector<vector<pii>>& graph, int start, vector<int>& distances) {
    int V = graph.size();
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> visited(V, false);

    // Initialize distances to infinity
    distances.assign(V, numeric_limits<int>::max());

    // Distance of start vertex from itself is 0
    distances[start] = 0;

    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Ignore if already visited
        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        // Update distances of adjacent vertices
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push({distances[v], v});
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<pii>> graph(V);

    cout << "Enter the source, destination, and weight of each edge:" << endl;
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src].push_back({dest, weight});
    }

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    vector<int> distances;
    dijkstra(graph, start, distances);

    cout << "Shortest distances from vertex " << start << ":" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}


output:


Enter the number of vertices: 5
Enter the number of edges: 7
Enter the source, destination, and weight of each edge:
0 1 4
0 2 1
1 3 3
1 2 2
2 1 1
2 3 4
3 4 2
Enter the starting vertex: 0
