// 78. Subsets

class Solution {
public:
    void helper(int idx, vector<int>& temp, vector<vector<int>>& result, vector<int>& nums){
        if (idx == nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        helper(idx+1, temp, result, nums);
        temp.pop_back();
        helper(idx+1, temp, result, nums);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;

        int i = 0;
        helper(i, temp, result, nums);        
        return result;
    }
};

// Time Complexity : O(2^N x N)
// Space Complexity : O(N)
