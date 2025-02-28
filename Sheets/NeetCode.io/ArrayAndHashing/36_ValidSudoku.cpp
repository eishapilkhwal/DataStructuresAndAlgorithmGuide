// 36. Valid Sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> bucket;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if (board[i][j] == '.')
                    continue;
                
                string row = string(1, board[i][j]) + "_ROW_" + to_string(i);
                string col = string(1, board[i][j]) + "_COL_" + to_string(j);
                string box = string(1, board[i][j]) + "_BOX_" + to_string(i/3) + "_" + to_string(j/3);

                if (bucket.find(row) != bucket.end() || bucket.find(col) != bucket.end() || bucket.find(box) != bucket.end()){
                    return false;
                }

                bucket.insert(row);
                bucket.insert(col);
                bucket.insert(box);
            }
        }
        return true;
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(n);
