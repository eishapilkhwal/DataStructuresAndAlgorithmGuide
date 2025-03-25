// 662. Maximum Width of Binary Tree

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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int sizeQueue = q.size();
            int minIndex = q.front().second;
            int first, last;
            for(int i = 0; i < sizeQueue; i++){
                long long curr_id = q.front().second - minIndex;
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0){
                    first = curr_id;
                }
                if (i == sizeQueue - 1){
                    last = curr_id;
                }
                if (node->left != nullptr){
                    q.push({node->left, 2*curr_id + 1});
                }
                if (node->right != nullptr){
                    q.push({node->right, 2*curr_id + 2});
                }
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};

// Time Complexity : O(N)
