// 94. Binary Tree Inorder Traversal

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL){
            return result;
        }
        TreeNode* node = root;
        stack<TreeNode*> st;
        while(true){
            if (node != nullptr){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()){
                    break;
                }
                node = st.top();
                result.push_back(node->val);
                st.pop();
                node = node->right;
            }
        }

        return result;
    }
};
