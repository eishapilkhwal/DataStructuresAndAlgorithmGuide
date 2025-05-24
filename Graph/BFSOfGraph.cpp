class Solution {
    public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int startNode = 0;
        int n = adj.size();
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(startNode);
        visited[startNode] = 1;
        vector<int> searchList;
        
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            searchList.push_back(node);
            for(auto it : adj[node]){
                if(!visited[it]){
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return searchList;
        
    }
};
