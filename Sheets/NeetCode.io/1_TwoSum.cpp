// 1. Two Sum


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            int a = nums[i];
            int more = target - a;
            if (map.find(more) != map.end()){
                return {map[more], i};
            }
            map[a] = i;
            
        }
        return {-1, -1};
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
