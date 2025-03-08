// 704. Binary Search

class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high, int target){
        if(low > high){
            return -1;
        }
        int mid = (low + high)/2;

        if(target == nums[mid]){
            return mid;
        }
        else if (target < nums[mid]){
            return binarySearch(nums, low, mid - 1, target);
        }
        else{
            return binarySearch(nums, mid + 1, high, target);
        }
    }
    
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        return binarySearch(nums, low, high, target);
    }
};

// Time Complexity : O(log N)
// Space Complexity : O(1)
