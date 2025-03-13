// 138. Copy List with Random Pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) 
            return nullptr;

        Node* temp = head;

        while(temp){
            Node* copyNode = new Node(temp->val);
            copyNode->next =  temp->next; 
            temp->next = copyNode;
            temp = copyNode->next;
        }  

        temp = head;

        while (temp) {
            if (temp->random) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        Node* dummy = new Node(-1);
        Node* res = dummy;
        temp = head;

        while(temp){
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;
        }

        return dummy->next;

    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)
