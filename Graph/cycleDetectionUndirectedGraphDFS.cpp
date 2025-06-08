// Cycle Detection in Undirected Graph using DFS


class Solution {
    
  private:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        
        for(auto adjacentNode : adj[node]){
            if (!visited[adjacentNode]){
                if(dfs(adjacentNode, node, adj, visited) == true){
                    return true;
                }
            }
            else if (adjacentNode != parent){
                    return true;
            }
        }
        return false;
    }
    
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        
        // Step 1 : Convert to Adjacency List 
        vector<vector<int>> adj(V);
        
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V, false);
        
        int node = 0;
        int parent = -1;
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if (dfs(i, parent, adj, visited) == true){
                    return true;
                }
            }
        }
        return false;
        
            
    }
};


// Time Complexity : O(N+2E) + O(N)
// Space Complexity : O(N) + O(N)
