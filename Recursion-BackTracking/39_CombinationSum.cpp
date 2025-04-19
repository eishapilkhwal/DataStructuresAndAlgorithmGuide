// 39. Combination Sum

class Solution {
public:
    void helper(int index, int target, vector<int> candidates, vector<int>& ds, vector<vector<int>>& result){
         if (index == candidates.size()){   
            if (target == 0){
                result.push_back(ds);
            }
            return;
         }

        if(target >= candidates[index]){
            ds.push_back(candidates[index]);
            helper(index, target - candidates[index], candidates, ds, result);
            ds.pop_back();
        }
        helper(index + 1, target, candidates, ds, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ds;
        int index = 0;

        helper(index, target, candidates, ds, result);

        return result;
    }
};

// Time Complexity : (2^t) * k
