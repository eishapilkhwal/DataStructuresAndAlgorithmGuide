206. Reverse Linked List

// Method : Using Recursion

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL){
            return head;
        }

        ListNode* newNode = reverseList(head->next);

        head->next->next = head;
        head->next = nullptr;

        return newNode;
    }
};

// Time Complexity : O(N)
// Space Complecity : O(N)

// -------------------------------------------

// Using Stack

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;

        while(temp){
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;
        while(temp){
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }

        return head;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)

// --------------------------------------------------

// Iterative


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        while(head){
            ListNode* newNode = head->next;
            head->next = prev;
            prev = head;
            head = newNode;

        }

        return prev;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)

