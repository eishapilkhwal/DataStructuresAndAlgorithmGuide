// 105. Construct Binary Tree from Preorder and Inorder Traversal

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
    TreeNode* convertToBinaryTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inMap){
        if (preStart > preEnd || inStart > inEnd){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = inMap[root->val];
        int numLeft = inRoot - inStart;
        
        root->left = convertToBinaryTree(preorder, preStart + 1, preStart + numLeft, inorder, inStart, inRoot - 1, inMap);
        root->right = convertToBinaryTree(preorder, preStart + numLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int, int> inMap;

        for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        int preStart = 0;
        int preEnd = preorder.size() - 1;
        int inStart = 0;
        int inEnd = inorder.size() - 1;

        TreeNode* root = convertToBinaryTree(preorder, preStart, preEnd, inorder, inStart, inEnd, inMap);

        return root;
    }
};


// Time Complexity : O(N)
// Space Complexity : O(N)
