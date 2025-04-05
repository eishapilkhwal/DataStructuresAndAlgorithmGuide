// 1448. Count Good Nodes in Binary Tree

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
    int countGoodNode(TreeNode* root, int maxVal){
        if (root == nullptr){
            return 0;
        }
        int countNode = 0;
        if (root->val >= maxVal){
            countNode = 1;
            maxVal = root->val;
        }
        int lh = countGoodNode(root->left, maxVal);
        int rh = countGoodNode(root->right, maxVal);

        return lh + rh + countNode;
    }
    int goodNodes(TreeNode* root) {
        return countGoodNode(root, INT_MIN);
    }
};

// Time Complexity : O(N)
// Space Complexity : O(height)
