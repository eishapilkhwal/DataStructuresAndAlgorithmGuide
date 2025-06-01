// 547. Number of Provinces


// Using BFS by converting the adjacency matrix into adjacency list 

class Solution {
public:
    void bfs(int node, vector<vector<int>>& adjLst, vector<int>& visited){
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        while(!q.empty()){
            int element = q.front();
            q.pop();
            for(auto it : adjLst[element]){
                if(!visited[it]){
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> adjLst (n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjLst[i].push_back(j);
                }
            }
        }
        vector<int> visited(n, 0);
       
        int count = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                count++;
                bfs(i, adjLst, visited);
            }
        }
        return count;
    }
};



// Using BFS on adjacency list 

class Solution {
public:
    void bfs(int node, vector<vector<int>>& adjLst, vector<int>& visited) {
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        while (!q.empty()) {
            int element = q.front();
            q.pop();
            for (int i = 0; i < adjLst.size(); i++) {
                if (!visited[i] && adjLst[element][i] == 1) {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> visited(n, 0);

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                bfs(i, isConnected, visited);
            }
        }
        return count;
    }
};
