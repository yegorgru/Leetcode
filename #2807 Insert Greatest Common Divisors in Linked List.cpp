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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        auto savedHead = head;
        while(head->next) {
            auto next = head->next;
            ListNode* gcdNode = new ListNode(gcd(head->val, next->val), next);
            head->next = gcdNode;
            head = next;
        }
        return savedHead;
    }
};
