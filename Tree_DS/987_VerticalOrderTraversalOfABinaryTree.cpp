// 987. Vertical Order Traversal of a Binary Tree

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // col -> vertical
        // row -> level

        TreeNode* node = root;
        queue<pair<TreeNode*, pair<int, int>>> q; // queue<pair<node, pair<col, row>>>
        map<int, map<int, multiset<int>>> mp;  // map<col, map<row, multiset<node>>>

        q.push({node, {0, 0}});
        while(!q.empty()){
            auto p = q.front();
            TreeNode* temp = p.first;
            int row = p.second.first;
            int col = p.second.second;
            q.pop();
            mp[col][row].insert(temp->val);

            if (temp->left != nullptr){
                q.push({temp->left, {row + 1, col - 1}});
            }
            if (temp->right != nullptr){
                q.push({temp->right, {row + 1, col + 1}});
            }
            
        }

        vector<vector<int>> result;
        for(auto& x : mp){
            vector<int> columnWise;
            for(auto& y : x.second){
                columnWise.insert(columnWise.end(), y.second.begin(), y.second.end());
            }
            result.push_back(columnWise);
        }

        return result;

    }
};

// Time Complexity : O(N logN)
// Space Complexity : O(N)
