257. Binary Tree Paths

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
    void getPath(TreeNode* node, string path, vector<string>& result){
        if (node == nullptr){
            return;
        }
        path += to_string(node->val);
        if (node->left == nullptr && node->right == nullptr){
            result.push_back(path);
        }

        path += "->";
        if (node->left != nullptr){
            getPath(node->left, path, result);
        }
        if (node->right != nullptr){
            getPath(node->right, path, result);
        }

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root == nullptr){
            return result;
        }
        getPath(root, "", result);

        return result;

    }
};

// Time Complexity : O(N)
