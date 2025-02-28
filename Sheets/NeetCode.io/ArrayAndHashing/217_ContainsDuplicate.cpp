// https://leetcode.com/problems/contains-duplicate/description/

// Solution 1 : -- Runtime error : Issue: Heap Buffer Overflow

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

// Solution 2 : -- Accepted

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> frequency;
        for(int i = 0; i < nums.size(); i++){
            frequency[nums[i]]++;

            if (frequency[nums[i]] > 1){
                return true;
            }
        }
        return false;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
