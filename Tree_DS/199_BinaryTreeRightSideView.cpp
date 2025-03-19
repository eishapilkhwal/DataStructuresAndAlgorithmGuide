// 199. Binary Tree Right Side View

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
    void invertedPreOrderTraversal(TreeNode* node, int level,  vector<int>& result){
        if (node == nullptr){
            return;
        }
        if (level >= result.size()){
            result.push_back(node->val);
        }

        invertedPreOrderTraversal(node->right, level+1, result);
        invertedPreOrderTraversal(node->left, level+1, result);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        invertedPreOrderTraversal(root, 0, result);

        return result;
    }
};

// Time Complexity : O(N)
