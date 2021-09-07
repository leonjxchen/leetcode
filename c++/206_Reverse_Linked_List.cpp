// Given the head of a singly linked list, reverse the list, and return the reversed list.
// 
//  
// 
// Example 1:
// 
// 
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]
// Example 2:
// 
// 
// Input: head = [1,2]
// Output: [2,1]
// Example 3:
// 
// Input: head = []
// Output: []
//  
// 
// Constraints:
// 
// The number of nodes in the list is the range [0, 5000].
// -5000 <= Node.val <= 5000
//  
// 
// Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* p = head;
        ListNode* q = p->next;
        p->next = nullptr;
        while (q) {
            ListNode* r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        return p;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        auto* ptr = reverseList(head->next);
        if (ptr) {
            auto* p = head->next;
            if (p) {
                p->next = head;
                head->next = nullptr;
            }
            return ptr;
        }
        return head;
    }
};