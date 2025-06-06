// 110. Balanced Binary Tree

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
    int getHeight(TreeNode* node){
        if (node == nullptr){
            return 0;
        }
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        if(leftHeight == -1 || rightHeight == -1){
            return -1;
        }

        if (abs(leftHeight - rightHeight) > 1){
            return -1;
        }

        
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        TreeNode* node = root;

        return (getHeight(node) == -1) ? false : true;
    }
};

// Best Case : O(log N)
// Worst Case : O(N)
