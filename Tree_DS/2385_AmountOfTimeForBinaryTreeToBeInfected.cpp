// 2385. Amount of Time for Binary Tree to Be Infected

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
    TreeNode* parentTrack(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap, int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* startNode = nullptr;
        while(!q.empty()){
    
            TreeNode* node = q.front();
            q.pop();

            if (node->val == start){
                startNode = node;
            }
            

            if (node->left != nullptr){
                parentMap[node->left] = node;
                q.push(node->left);
            }

            if (node->right != nullptr){
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }

        return startNode;
    }


    int amountOfTime(TreeNode* root, int start) {
        // Step 1 : Parent Map
        unordered_map<TreeNode*, TreeNode*> parentMap;
        TreeNode* startNode = parentTrack(root, parentMap, start);

        // Step 2 : To identify the node of start
        if (!startNode) 
            return 0;

        // Step 3 : Caluculate time when whole tree got infected

        queue<TreeNode*> q;
        unordered_set<TreeNode*> burnt;
        q.push(startNode);
        burnt.insert(startNode);
        int timeBurn = 0;

        while(!q.empty()){
            int queueSize = q.size();
            bool burn = false;
            for(int i = 0; i < queueSize; i++){
                TreeNode* node = q.front();
                q.pop();

                if (node->left != nullptr && burnt.find(node->left) == burnt.end()){
                    q.push(node->left);
                    burnt.insert(node->left);
                    burn = true;
                }

                if (node->right != nullptr && burnt.find(node->right) == burnt.end()){
                    q.push(node->right);
                    burnt.insert(node->right);
                    burn = true;
                }

                if (parentMap.find(node) != parentMap.end() && burnt.find(parentMap[node]) == burnt.end()){
                    q.push(parentMap[node]);
                    burnt.insert(parentMap[node]);
                    burn = true;
                }
            }
            if (burn){
                timeBurn++;
            }
            
        }
        return timeBurn;
    }
};

// Time and Space Complexity : O(N)
