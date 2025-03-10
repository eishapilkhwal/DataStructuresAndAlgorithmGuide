// 19. Remove Nth Node From End of List

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int len = 0;
        ListNode* temp = head;

        while(temp){
            len++;
            temp = temp->next;
        }

        if (n == len) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int counter = 1;
        temp = head;
        ListNode* prev = nullptr;
        while(counter < len - n + 1){
            prev = temp;
            temp = temp->next;
            counter++;
        }
        prev->next = temp->next;
        delete temp;
        
        return head;
        
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)
