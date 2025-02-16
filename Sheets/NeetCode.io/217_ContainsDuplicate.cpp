// https://leetcode.com/problems/contains-duplicate/description/

// Solution 1 : 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        vector<int> frequency (nums.size() + 1, 0) ;
        for(int i = 0; i < nums.size(); i++){
            frequency[nums[i]]++;

            if (frequency[nums[i]] > 1){
                return true;
            }
        }
        return false;
    }
};
