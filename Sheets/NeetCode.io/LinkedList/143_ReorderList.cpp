// 143. Reorder List

class Solution {
public:
    ListNode* current;

    void solve(ListNode* head){
        if(head == NULL){
            return;
        }
        solve(head->next);
        ListNode* temp = current->next;
        if(current->next == NULL){
            return;
        }
        else if (head == current){
            head->next = NULL;
            return;
        }

        current->next = head;
        head->next = (temp == head) ? NULL : temp;

        current = temp;
    }

    void reorderList(ListNode* head) {
        current = head;
        solve(head);
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)

