// 25. Reverse Nodes in k-Group

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reverseList(ListNode* head) {
        ListNode* prev = NULL;
        while(head){
            ListNode* newNode = head->next;
            head->next = prev;
            prev = head;
            head = newNode;

        }

    }
    ListNode* findKNode(ListNode* temp, int k){
        k -= 1;
        while(temp != NULL && k > 0){
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while(temp != NULL){
            ListNode* kNode = findKNode(temp, k);
            if(kNode == NULL){
                prevNode->next = temp;
                break;
            }

            ListNode* nextNode = kNode->next;
            kNode->next = NULL;
            reverseList(temp);
            if(temp == head){
                head = kNode;
            }
            else{
                prevNode->next = kNode;
            }
            prevNode = temp;
            temp = nextNode;

        }
        return head;
    }
};

// Time Complexity : O(N)
