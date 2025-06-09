// Distance of nearest cell having 1


class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        
        int n  = grid.size();
        int m = grid[0].size();
        int distance = 0;
        
        queue<pair<pair<int, int>, int>>q;
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        vector<vector<int>> steps(n, vector<int> (m, -1));
        
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (grid[i][j] == 1){
                    q.push({{i, j}, distance});
                    visited[i][j] = true;
                }
                
            }
        }
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            
            int dist = q.front().second;
            
            steps[row][col] = dist;
            
            q.pop();
            
            int dRow[] = {-1, 0, +1, 0};
            int dCol[] = {0, +1, 0, -1};
            
            for(int i = 0; i < 4; i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
                
                if (nRow >= 0 && nRow < n 
                && nCol >= 0 && nCol < m 
                && !visited[nRow][nCol] && steps[nRow][nCol] == -1){
                    q.push({{nRow, nCol}, dist + 1});
                    visited[nRow][nCol] = true;
                    // distance[nRow][nCol] = dist + 1;
                }
            }
        }
        
        return steps;
        
    }
};

// Time Complexity : O(N X M)
// Space Complexity : O(N X M)
