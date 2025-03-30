// 863. All Nodes Distance K in Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap){
        queue <TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sizeQueue = q.size();
            for(int i = 0; i < sizeQueue; i++){
                TreeNode* node = q.front();
                q.pop();
                if (node->left != nullptr){
                    q.push(node->left);
                    parentMap[node->left] = node;
                }
                if (node->right != nullptr){
                    q.push(node->right);
                    parentMap[node->right] = node;
                }
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        
        markParent(root, parentMap);
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        int currLevel = 0;
        while(!q.empty()){
            
            if (currLevel == k)
                break;
            int sizeQueue = q.size();
            for(int i = 0; i < sizeQueue; i++){
                TreeNode* node = q.front();
                q.pop();
                
                if (node->left != nullptr && visited.find(node->left) == visited.end()){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right != nullptr && visited.find(node->right) == visited.end()){
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if (parentMap.find(node) != parentMap.end() && visited.find(parentMap[node]) == visited.end()){
                    q.push(parentMap[node]);
                    visited.insert(parentMap[node]);
                }
            }
            currLevel++;
        }
        vector<int> result;
        while (!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)
