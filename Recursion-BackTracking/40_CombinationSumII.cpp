// 40. Combination Sum II

class Solution {
public:
    void findCombinations(int index, int target, vector<int>& candidates, vector<int>& ds, vector<vector<int>>& result){
        if(target == 0){
            result.push_back(ds);
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }

            if (candidates[i] > target){
                break;
            }

            ds.push_back(candidates[i]);
            findCombinations(i+1, target - candidates[i], candidates, ds, result);
            ds.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> ds;
        int index = 0;
        findCombinations(0, target, candidates, ds, result);

        return result;
    }
};

// Time Complexity : O(2^n * k)
// Space Complexity : O(k * n)
