// 141. Linked List Cycle


// Using Extra Space

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        unordered_map<ListNode*, int> mp;

        while(temp){
            if (mp.find(temp) != mp.end()){
                return true;
            }
            mp[temp]++;
            temp = temp->next;
        }
        
        return false;
    }
};

// Time Complexity : O(N)
// Space Complexity : ON)

// Tortoise and the Hare -- fast and the slow pointer

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false; 
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)


