// Detect cycle in an undirected graph usin BFS

class Solution {
private:
    bool detectCycle(int src, vector<vector<int>>& edges, vector<bool>& visited) {
        visited[src] = true;
        queue<pair<int, int>> q;
        q.push({src, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int adjacentNode : edges[node]) {
                if (!visited[adjacentNode]) {
                    visited[adjacentNode] = true;
                    q.push({adjacentNode, node});
                } else if (adjacentNode != parent) {
                    return true; // Cycle found
                }
            }
        }

        return false; // No cycle
    }

public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<bool> visited(V, false);
        
        vector<vector<int>> adj(V);
        
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (detectCycle(i, adj, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};


// Time Complexity : O(N+2E) + O(N)
// Space Complexity : O(N) + O(N)
