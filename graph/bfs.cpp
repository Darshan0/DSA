#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Space Complexity = 0(3N) = 0(N)
// Time Complexity = 0 (N) + 0 (2E)

class BFS {
    public:
        static vector<int> bfsOfGraph(int n, vector<vector<int> > &adj, int start) {
            // step 1 : we will create a visited array and a queue.
            vector<int> visited(n,0);
            queue<int> q;
            // step 2 : we will add the starting index into the queue and mark it visited.
            q.push(start);
            visited[start] = 1;

            // initialize the bfs vector
            vector<int> bfs;

            while(!q.empty()){
                // we take it out of the queue check with if it had as any adjecent node
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                // we check if the node has any adjecent nodes and push them into the stack
                for(auto it: adj[node]){
                    if(visited[it] != 1) {
                        visited[it] = 1;
                        q.push(it);
                    }
                }
            }

            return bfs;
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

    vector<int> bfsResult = BFS::bfsOfGraph(n, adj, 0);

    for (int node : bfsResult) {
        cout<< node << "";
    }

    return 0;
}
