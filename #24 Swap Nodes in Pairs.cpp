#include <vector>
#include <iostream>

//Swap Nodes in Pairs

//https://leetcode.com/problems/swap-nodes-in-pairs/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* res = head;
        while (head != nullptr) {
            if (head->next) {
                std::swap(head->val, head->next->val);
                head = head->next->next;
            }
            else {
                return res;
            }
        }
        return res;
    }
};
