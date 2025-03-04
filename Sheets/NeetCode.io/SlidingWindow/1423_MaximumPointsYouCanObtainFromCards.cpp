// 1423. Maximum Points You Can Obtain from Cards

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // Step 1 : sum of k elements from starting
        int leftSum = 0;
        for(int i = 0; i < k; i++){
            leftSum += cardPoints[i];
        }
        int maxPoint = leftSum;
        
        // Step 2 : removing element from left and adding from right
        int rightIndex = cardPoints.size() - 1;
        int rightSum = 0;
        for(int i = k - 1; i >= 0; i--){
            leftSum = leftSum - cardPoints[i];
            rightSum = rightSum + cardPoints[rightIndex];
            maxPoint = max(maxPoint, leftSum + rightSum);
            rightIndex--;
        }

        return maxPoint;
    }
};

// Time Complexity : O(k)
// Space Complexity : O(1)
