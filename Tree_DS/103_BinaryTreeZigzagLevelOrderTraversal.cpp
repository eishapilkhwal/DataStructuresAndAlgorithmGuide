// 103. Binary Tree Zigzag Level Order Traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr){
            return result;
        }
        queue<TreeNode*> q;
        bool leftToRight = true;
        q.push(root);
        while(!q.empty()){  
            int levelSize = q.size();
            vector<int> level (levelSize, 0);
            for(int i = 0; i < levelSize; i++){
                TreeNode* node = q.front();
                q.pop();
                int index = (leftToRight) ? i : (levelSize - i - 1);
                level[index] = node->val;
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);

            }
            leftToRight = !leftToRight;
            result.push_back(level);
        }
        return result;
    }
};

// Time Complexity : O(N)
