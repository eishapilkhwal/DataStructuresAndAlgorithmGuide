// 124. Binary Tree Maximum Path Sum

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getSum(TreeNode* node, int& maxSum){
        if (node == nullptr){
            return 0;
        }

        int leftSum = max(0 ,getSum(node->left, maxSum));
        int rightSum = max(0, getSum(node->right, maxSum));
        maxSum = max(maxSum, node->val + leftSum + rightSum);
        return node->val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int maxPathSum = getSum(root, maxSum);
        return maxSum;
    }
};

// Time Complexity 
// Best Case : O(log N)
// Worst Case : O(N)
