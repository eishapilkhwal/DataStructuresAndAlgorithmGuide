// 297. Serialize and Deserialize Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if (root == nullptr){
            return s;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr){
                s.append("#,");
            }
            else{
                s.append(to_string(node->val) + ',');
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0){
            return nullptr;
        }
        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){

            TreeNode* node = q.front();
            q.pop();
            
            getline(s, str, ',');
            if (str == "#"){
                node->left = nullptr;
            }
            else{
                TreeNode* leftChild = new TreeNode(stoi(str));
                node->left = leftChild;
                q.push(leftChild);
            }

            getline(s, str, ',');
            if (str == "#"){
                node->right = nullptr;
            }
            else{
                TreeNode* rightChild = new TreeNode(stoi(str));
                node->right = rightChild;
                q.push(rightChild);
            }
        }
        return root; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


// Time Complexity : Serialize O(N); Deserialize O(N)
// Space Complexity : Serialize O(N); Deserialize O(N)
