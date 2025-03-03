// 42. Trapping Rain Water

class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int maxArea = 0;
        int leftMax = 0;
        int rightMax = 0;

        while(start < end){
            if (height[start] <= height[end]){
                if(leftMax > height[start]){
                    maxArea += leftMax - height[start];
                }
                else{
                    leftMax = height[start];
                }
                start++;
            }
            else{
                if(rightMax > height[end]){
                    maxArea += rightMax - height[end];
                }
                else{
                    rightMax = height[end];
                }
                end--;
            }
        }

        return maxArea;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)
