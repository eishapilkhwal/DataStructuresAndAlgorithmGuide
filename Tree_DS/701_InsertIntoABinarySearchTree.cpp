// 701. Insert into a Binary Search Tree

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr){
            return new TreeNode(val);
        }
        TreeNode* node = root;
        while(node){
            if(node->val > val){
                if (node->left == nullptr){
                    node->left = new TreeNode(val);
                    break;
                }
                else{
                    node = node->left;
                }
            }
            else{
                if (node->right == nullptr){
                    node->right = new TreeNode(val);
                    break;
                }
                else{
                    node = node->right;
                }
            }

        }
        return root;
    }
};

// Time Complexity : O(log N)
