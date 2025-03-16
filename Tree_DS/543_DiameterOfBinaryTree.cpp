// 543. Diameter of Binary Tree

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
    int getHeight(TreeNode* node, int& maxDiameter){
        if (node == nullptr){
            return 0;
        }
        int leftHeight = getHeight(node->left, maxDiameter);
        int rightHeight = getHeight(node->right, maxDiameter);

        
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);
    

        return 1 + max(leftHeight, rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        TreeNode* node = root;
        int maxDiameter = INT_MIN;
        int height = getHeight(node, maxDiameter);
        return maxDiameter;
    }
};

// Time Complexity 
// Best Case : O(log N)
// Worst Case : O(N)
