#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adjMatrix;

public:
    Graph(int V) {
        this->V = V;
        adjMatrix.resize(V, vector<int>(V, 0));
    }
    
    void addvertex(int i){
    	int newV = i+V;
    	adjMatrix.resize(newV, vector<int>(newV,0));
    	V = newV;
    	
	}
	
    void removeVertex(int v) {
        adjMatrix.erase(adjMatrix.begin() + v);
        for (int i = 0; i < adjMatrix.size(); ++i) {
            adjMatrix[i].erase(adjMatrix[i].begin() + v);
        }
        V--;
    }


    void addEdge(int v, int w) {
        adjMatrix[v][w] = 1;
        adjMatrix[w][v] = 1;
    }
    
    void removeEdge(int v, int w){
    	adjMatrix[v][w]=0;
    	adjMatrix[w][v]=0;
    	
	}

    void DFS(int startVertex) {
        vector<bool> visited(V, false);
        stack<int> stack;

        stack.push(startVertex);
        visited[startVertex] = true;

        while (!stack.empty()) {
            int currentVertex = stack.top();
            stack.pop();
            cout << getLetter(currentVertex) << " ";

            for (int i = 0; i < V; ++i) {
                if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                    stack.push(i);
                    visited[i] = true;
                }
            }
        }
    }

	char getLetter(int vertex) {
		char letter = 'A' + (vertex % 26);
		return letter;
	}
};
  
int main() {
    int numVertices = 5;
    Graph g(numVertices);
    
    g.addEdge(2, 3);
    g.addEdge(2, 1);
    g.addEdge(3, 0);
    g.addEdge(1, 0);
    


	cout << "before removing vertex: " << endl;
    cout << "Depth First Traversal (DFS): ";
    g.DFS(0);
    
    cout << "\n\nafter removing vertex: " << endl;
    g.removeVertex(2);
    g.DFS(0);

    return 0;
}
