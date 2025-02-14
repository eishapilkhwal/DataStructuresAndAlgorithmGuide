// Binary Tree Implementation

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int root;
    Node* leftChild;
    Node* rightChild;

    Node(int key){
        root = key;
        leftChild = nullptr;
        rightChild = nullptr;
    }
};

int idx = -1;

Node* buildTree(const vector<int>& nodeArray){
    idx++;

    if (nodeArray[idx] == -1){
        return nullptr;
    }
    
    Node* newNode = new Node(nodeArray[idx]);
    newNode->leftChild = buildTree(nodeArray);
    newNode->rightChild = buildTree(nodeArray);

    return newNode;

}

int main(){
    vector<int> nodeArray = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* tree = buildTree(nodeArray);
    cout << tree->root;

    return 0;
}

