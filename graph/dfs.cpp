#include <iostream>
#include <vector>

using namespace std;

class DFS {
    private:
    void dfs(int node , vector<vector<int> > &adj , vector<int> visited, vector<int> &dfsvector) {
        visited[node] = 1;
        dfsvector.push_back(node);
        for (auto it: adj[node]) {
            if(visited[it] != 1) {
                dfs(it, adj, visited, dfsvector);
            }
        }
    }
    public:
    vector<int> dfsOfGraph(int n , vector<vector<int> > &adj , int start) {
        vector<int> visited(n,0);
        vector<int> dfs_vector;
        dfs(start,adj,visited,dfs_vector);
        return dfs_vector;
    }
};

int main() {

    int n = 5;  // Number of vertices

    // Declare the adjacency list as a vector of vectors
    vector<vector<int> > adj(n);

    // Assigning adjacency lists using push_back
    adj[0].push_back(1);
    adj[0].push_back(2);

    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[1].push_back(4);

    adj[2].push_back(0);

    adj[3].push_back(1);

    adj[4].push_back(1);

    vector<int> dfsResult = DFS().dfsOfGraph(n, adj, 0);

    for (int node : dfsResult) {
        cout<< node << "";
    }

    return 0;
}
