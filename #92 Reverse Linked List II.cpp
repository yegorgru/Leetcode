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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == 1) {
            reverseList(head, right - left);
            head->next = rightBoundNext;
            return rightBound;
        }
        else {
            ListNode* res = head;
            int counter = 1;
            while(counter < left) {
                leftBound = head;
                head = head->next;
                ++counter;
            }
            reverseList(head, right - left);
            leftBound->next = rightBound;
            head->next = rightBoundNext;
            return res;
        }
    }

private:
    ListNode* reverseList(ListNode* head, int depth) {
        if(depth == 0) {
            rightBoundNext = head->next;
            rightBound = head;
            return head;
        }
        else {
            auto prev = reverseList(head->next, depth - 1);
            prev->next = head;
            return head;
        }
    }

private:
    ListNode* leftBound = nullptr;
    ListNode* rightBound = nullptr;
    ListNode* rightBoundNext = nullptr;
};
