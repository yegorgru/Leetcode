
//Add Two Numbers

//https://leetcode.com/problems/add-two-numbers/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwo(l1, l2, 0);
    }

    ListNode* addTwo(ListNode* l1, ListNode* l2, bool in_memory) {
        if (l1 && l2) {
            int ans_dig = in_memory + l1->val + l2->val;
            in_memory = ans_dig / 10;
            ans_dig = ans_dig % 10;
            ListNode* next = addTwo(l1->next, l2->next, in_memory);
            return new ListNode(ans_dig, next);
        }
        else if (l1) {
            return addSingle(l1, in_memory);
        }
        else if (l2) {
            return addSingle(l2, in_memory);
        }
        else if (in_memory) {
            return new ListNode(1);
        }            
        else {
            return nullptr;
        }
    }

    ListNode* addSingle(ListNode* l, bool in_memory) {
        if (l) {
            int ans_dig = in_memory + l->val;
            in_memory = ans_dig / 10;
            ans_dig = ans_dig % 10;
            ListNode* next = addSingle(l->next, in_memory);
            return new ListNode(ans_dig, next);
        }
        else if (in_memory) {
            return new ListNode(1);
        }
        else {
            return nullptr;
        }
    }
};