#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define INF INT_MAX

class Graph {
    int V;
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight));
    }

    vector<int> dijkstraShortestPath(int source) {
        vector<int> dist(V, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[source] = 0;
        pq.push(make_pair(0, source));

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        return dist;
    }

    void dfsUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (auto neighbor : adjList[v]) {
            int u = neighbor.first;
            if (!visited[u]) {
                dfsUtil(u, visited);
            }
        }
    }

    void dfs(int source) {
        vector<bool> visited(V, false);
        dfsUtil(source, visited);
    }
};

int main() {
    int numVertices = 6;
    Graph g(numVertices);

    g.addEdge(0, 1, 2);
    g.addEdge(2, 0, 7);
    g.addEdge(2, 1, 5);
    g.addEdge(2, 3, 5);
    g.addEdge(1, 4, 7);

    int source = 0;
    vector<int> shortestDistances = g.dijkstraShortestPath(source);

    for (int i = 0; i < numVertices; ++i) {
        if (shortestDistances[i] != INF) {
            cout << "Shortest distance from vertex " << source << " to vertex " << i << ": " << shortestDistances[i] << endl;
        } else {
            cout << "There is no path from vertex " << source << " to vertex " << i << endl;
        }
    }

    cout << "DFS traversal starting from vertex " << source << ": ";
    g.dfs(source);

    return 0;
}
