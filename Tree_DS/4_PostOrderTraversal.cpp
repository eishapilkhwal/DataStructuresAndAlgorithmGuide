// PostOrder traversal - DFS
// Time Complexity O(n)

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int root;
    Node * leftChild;
    Node * rightChild;

    Node(int key){
        root = key;
        leftChild = nullptr;
        rightChild = nullptr;
    }
};

int idx = -1;
Node* buildTree(vector<int>& NodeArray){
    idx++;
    if(NodeArray[idx] == -1){
        return nullptr;
    }
    Node * newNode = new Node(NodeArray[idx]);
    newNode->leftChild = buildTree(NodeArray);
    newNode->rightChild = buildTree(NodeArray);

    return newNode;
}

void postOrderTraversal(Node * tree){
    if(tree == nullptr)
        return;
    
    postOrderTraversal(tree->leftChild);
    postOrderTraversal(tree->rightChild);
    cout << tree->root << " ";
}

int main(){
    vector<int> nodeArray = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node * tree = buildTree(nodeArray);
    cout << "Post Order Traversal : " << endl;
    postOrderTraversal(tree);

    return 0;
}