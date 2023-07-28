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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) {
            return nullptr;
        }
        int value = head->val;
        auto next = head->next;
        while (next && next->val == value) {
            head->next = next->next;
            delete next;
            next = head->next; 
        }
        head->next = deleteDuplicates(next);
        return head;
    }
};
