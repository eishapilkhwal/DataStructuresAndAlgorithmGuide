// 90. Subsets II

class Solution {
public:
    void helper(int index, vector<int>& nums, vector<int>& ds, vector<vector<int>>& result){
        result.push_back(ds);
        for(int i = index; i < nums.size(); i++){
            if(i > index && nums[i] == nums[i-1]){
                continue;
            }
            ds.push_back(nums[i]);
            helper(i+1, nums, ds, result);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        int index = 0;
        helper(index, nums, ds, result);

        return result;
    }
};

// Time Complexity : O(2^N * N)
// Space Complexity : O(2^N * N)
