// 238. Product of Array Except Self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProduct (nums.size(), 1) ;
        vector<int> result (nums.size(), 1);

        for(int i = 1; i < nums.size(); i++){
            leftProduct[i] = leftProduct[i-1] * nums[i-1];  
        }

        int rightProduct = 1;

        for(int j = nums.size()-1; j >= 0; j--){
            result[j] = result[j] * rightProduct;
            rightProduct *= nums[j];
        }
        return result;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
