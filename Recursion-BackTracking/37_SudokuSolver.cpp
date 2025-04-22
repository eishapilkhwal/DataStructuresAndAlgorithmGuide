// 37. Sudoku Solver

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
      solve(board);  
    }

    bool solve(vector<vector<char>>& board){
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board.size(); col++){
                if(board[row][col] == '.'){
                    for(char c  = '1'; c <= '9'; c++){
                        if(isValid(board, row, col, c)){
                            board[row][col] = c;

                            if(solve(board) == true)
                                return true;
                            else 
                                board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i = 0; i < 9; i++){
            if(board[i][col] == c)
                return false;
            
            if(board[row][i] == c)
                return false;
            
            // for 3*3 sub matrix
            if(board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c)
                return false;
        }

        return true;
    }
};

// Time Complexity : O(9^m) m : number of empty cell
// Space Complexity : O(1)
