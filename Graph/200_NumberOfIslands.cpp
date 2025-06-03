class Solution {
public:
    void bfs(int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& grid){
        visited[row][col] = true;

        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int dRow[] = {-1, 1, 0, 0};
            int dCol[] = {0, 0, -1, 1};

            for(int i = 0; i < 4; i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if(nRow >= 0 && nRow < grid.size() && nCol >= 0 && nCol <= grid[0].size() && !visited[nRow][nCol] && grid[nRow][nCol] == '1'){
                    q.push({nRow, nCol});
                    visited[nRow][nCol] = true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!visited[row][col] && grid[row][col] == '1'){
                    count++;
                    bfs(row, col, visited, grid);
                }

            }
        }
        return count;
    }
};


// Space Complexity : O(N * M) + O(N)
// Time Complexity : O(N * M)
