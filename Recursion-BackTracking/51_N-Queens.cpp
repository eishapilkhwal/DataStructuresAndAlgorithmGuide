// 51. N-Queens

class Solution {
public:
    void solve(int col, vector<string>& board, vector<vector<string>>& result, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n){
        if (col == n){
            result.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(leftRow[row] == 0 && upperDiagonal[(n-1) + (col - row)] == 0 && lowerDiagonal[row + col] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperDiagonal[(n-1) + (col - row)] = 1;
                lowerDiagonal[row + col] = 1;

                solve(col + 1, board, result, leftRow, upperDiagonal, lowerDiagonal, n);

                board[row][col] = '.';
                leftRow[row] = 0;
                upperDiagonal[(n-1) + (col - row)] = 0;
                lowerDiagonal[row + col] = 0;

            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);
        solve(0, board, result, leftRow, upperDiagonal, lowerDiagonal, n);
        return result;
    }
};

// Time Complexity : O(N!)
// Space Complexity : O(N)
