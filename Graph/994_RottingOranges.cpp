// 994. Rotting Oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited = grid;

        int countFresh = 0;
        int time = 0;

        // Find the rotten oranges at first.

        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 2){
                    q.push({{i, j}, time});
                    visited[i][j] = 2;
                }

                // Counting the fresh oranges

                if (grid[i][j] == 1){
                    countFresh++;
                }
            }
        }

        int maxTime = 0;

        int dRow[] = {-1, 0, +1, 0};
        int dCol[] = {0, +1, 0, -1};
        int cnt = 0;

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;

            q.pop();

            maxTime = max(maxTime, t);

            for(int i = 0; i < 4; i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if (nRow >= 0 && nRow < n 
                && nCol >= 0 && nCol < m
                && grid[nRow][nCol] == 1
                && visited[nRow][nCol] != 2){
                    q.push({{nRow, nCol}, t + 1});
                    visited[nRow][nCol] = 2;
                    cnt++;
                }
            }

        }

        if (cnt != countFresh) 
            return -1;
        return maxTime;

    }
};

// Time Complexity : O(N*M)
// Space Complexity : O(N*M)
