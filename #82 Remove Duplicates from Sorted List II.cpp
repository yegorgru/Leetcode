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
        if(next) {
            if(next->val == value) {
                while (head && head->val == value) {
                    auto next = head->next;
                    delete head;
                    head = next;
                }
                return deleteDuplicates(head);
            }
            else {
                head->next = deleteDuplicates(next);
                return head;
            }
        }
        else {
            return head;
        }
    }
};
