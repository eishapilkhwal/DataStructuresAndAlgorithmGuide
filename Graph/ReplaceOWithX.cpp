// Replace O's with X's

// User function Template for C++

class Solution {
  private:
    void dfs(int n, int m, int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& mat){
        visited[row][col] = true;
        
        int dRow[] = {-1, 0, +1, 0};
        int dCol[] = {0, +1, 0, -1};
        
        for(int i = 0; i < 4; i++){
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];
            
            if (nRow >= 0 && nRow < n
            && nCol >= 0 && nCol < m
            && !visited[nRow][nCol] 
            && mat[nRow][nCol] == 'O'){
                dfs(n, m, nRow, nCol, visited, mat);
            }
        }
    }
     
  public:
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        
        // Traversing the first row and the last row
        for(int j = 0; j < m; j++){
            // First Row
            if(!visited[0][j] && mat[0][j] == 'O'){
                dfs(n, m, 0, j, visited, mat);
            }
            
            // Last Row
            if (!visited[n-1][j] && mat[n-1][j] == 'O'){
                dfs(n, m, n-1, j, visited, mat);
            }
        }
        
        // Traversing the first column and the last colum
        for(int i = 0; i < n; i++){
            // First Row
            if(!visited[i][0] && mat[i][0] == 'O'){
                dfs(n, m, i, 0, visited, mat);
            }
            
            // Last Row
            if (!visited[i][m-1] && mat[i][m-1] == 'O'){
                dfs(n, m, i, m-1, visited, mat);
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (!visited[i][j] && mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }
        
        return mat;
        
    }
};

// Time Complexity : O(N X M)
// Space Complexity : O(N X M)
