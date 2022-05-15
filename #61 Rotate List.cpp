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
        if(!head) {
            return nullptr;
        }
        else if(!head->next) {
            return head;
        }
        int size = 0;
        auto headCopy = head;
        while(head) {
            ++size;
            head = head->next;
        }
        k %= size;
        if(k == 0) {
            return headCopy;
        }
        head = headCopy;
        for(int i = 0; i < size - k - 1; ++i) {
            head = head->next;
        }
        auto newHead = head->next;
        head->next = nullptr;
        head = newHead;
        for(int i = 0; i < k - 1; ++i) {
            head = head->next;
        }
        head->next = headCopy;
        return newHead;
    }
};
