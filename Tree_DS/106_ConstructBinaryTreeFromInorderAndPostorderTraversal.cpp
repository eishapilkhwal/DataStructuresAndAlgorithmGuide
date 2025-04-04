// 106. Construct Binary Tree from Inorder and Postorder Traversal

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
    TreeNode* convertToTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& inMap){
        if (inStart > inEnd || postStart > postEnd){
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = inMap[root->val];
        int numLeft = inRoot - inStart;
        root->left = convertToTree(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numLeft - 1, inMap);
        root->right = convertToTree(inorder, inRoot + 1, inEnd, postorder, postStart + numLeft, postEnd - 1, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        int inStart = 0;
        int inEnd = inorder.size()-1;
        int postStart = 0;
        int postEnd = postorder.size()-1;

        TreeNode* root = convertToTree(inorder, inStart, inEnd, postorder, postStart, postEnd, inMap);

        return root;
    }
};

// Time Complexity : 
// Space Compelxity : 
