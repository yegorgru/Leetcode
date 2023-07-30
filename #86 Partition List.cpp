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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = nullptr;
        ListNode* greater = nullptr;
        ListNode* lessTail = nullptr;
        ListNode* greaterTail = nullptr;
        while (head) {
            if(head->val < x) {
                if(!less) {
                    less = head;
                    lessTail = head;
                }
                else {
                    lessTail->next = head;
                    lessTail = head;
                }
            }
            else {
                if(!greater) {
                    greater = head;
                    greaterTail = head;
                }
                else {
                    greaterTail->next = head;
                    greaterTail = head;
                }
            }
            head = head->next;
        }
        if(lessTail) {
            lessTail->next = greater;
            if(greaterTail) {
                greaterTail->next = nullptr;
            }
            return less;
        }
        else {
            if(greaterTail) {
                greaterTail->next = nullptr;
            }
            return greater;
        }
    }
};
