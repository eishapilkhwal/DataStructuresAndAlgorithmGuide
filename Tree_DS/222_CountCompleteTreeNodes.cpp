// 222. Count Complete Tree Nodes

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
    int leftHeight(TreeNode* node){
        int height = 0;
        while(node){
            height++;
            node = node->left;
        }
        return height;
    }

    int rightHeight(TreeNode* node){
        int height = 0;
        while(node){
            height++;
            node = node->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }

        int rh = rightHeight(root);
        int lh = leftHeight(root);

        return (lh == rh) ? (1<<lh) - 1 : 1 + countNodes(root->left) + countNodes(root->right);
        
    }
};

// Time Complexity (Best) : O(logN)
// Time Complexity (Worst) : O((logN)^2)
// Space Complexity : O(1) , while recursion call O(logN) 
