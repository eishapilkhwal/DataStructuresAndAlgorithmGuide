// 74. Search a 2D Matrix

class Solution {
public:
    bool binarySearch (vector<vector<int>>& matrix, int low, int high, int target, int rowSize){
        if(low > high){
            return false;
        }

        int mid  = (low + high)/2;

        if(target > matrix[mid/rowSize][mid%rowSize]){
            return binarySearch(matrix, mid + 1, high, target, rowSize);
        }
        else if (target < matrix[mid/rowSize][mid%rowSize]){
            return binarySearch(matrix, low, mid - 1, target, rowSize);
        }
        else{
            return true;
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int m = matrix.size();
        int low = 0;
        int high = (m * n) - 1;

        return binarySearch(matrix, low, high, target, n);
        
    }
};

// Time Complexity : O(log (m*n))
// Space Complexity : O(1)
