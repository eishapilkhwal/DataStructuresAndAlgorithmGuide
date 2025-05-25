// Depth First Search Of Graph

class Solution {
  public:
    void helper(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& traversedList){
        visited[node] = 1;
        traversedList.push_back(node);
        for(auto it: adj[node]){
            if (!visited[it]){
                helper(it, adj, visited, traversedList);
            }
        }

        
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> visited (n, 0);
        
        vector<int> traversedList;
        int startNode = 0;
        
        helper(startNode, adj, visited, traversedList);
        
        return traversedList;
        
    }
};

// Space Complexity : O(N)
// Time Complexity : O(N) + (2E)
