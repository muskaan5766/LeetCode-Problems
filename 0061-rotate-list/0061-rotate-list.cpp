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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }
        
        // Find the length and the tail node
        int length = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }
        
        // Calculate effective rotation count
        k = k % length;
        if (k == 0) {
            return head;
        }
        
        // Find the new tail (length - k - 1 steps from head)
        ListNode* new_tail = head;
        for (int i = 0; i < length - k - 1; i++) {
            new_tail = new_tail->next;
        }
        
        // Perform rotation
        ListNode* new_head = new_tail->next;
        new_tail->next = nullptr;
        tail->next = head;
        
        return new_head;
    }
};