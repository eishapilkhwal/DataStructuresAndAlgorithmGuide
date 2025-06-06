// 733. Flood Fill

class Solution {
  public:
    void dfs(vector<vector<int>>& image, int row, int col, int initialColor, int newColor, vector<vector<int>>& resultantImage){
        resultantImage[row][col] = newColor;

        int dRow[] = {-1, 0, +1, 0};
        int dCol[] = {0, +1, 0, -1};
        
        for(int i = 0; i < 4; i++){
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];
            if (nRow >= 0 && nRow < resultantImage.size() 
                && nCol >= 0 && nCol < resultantImage[0].size() 
                && resultantImage[nRow][nCol] == initialColor 
                && image[nRow][nCol] != newColor){
                dfs(image, nRow, nCol, initialColor, newColor, resultantImage);
            }
        }
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int initialColor = image[sr][sc];
        vector<vector<int>> resultantImage = image;
        dfs(image, sr, sc, initialColor, newColor, resultantImage);
        
        return resultantImage;
    }
};

// Time Complexity : O(N*M)
// Space Complexity : O(N*M) + O(N*M)
