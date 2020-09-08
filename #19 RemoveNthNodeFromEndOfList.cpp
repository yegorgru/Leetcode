#include <set>
#include <utility>
#include <algorithm>

#include "Header.h"

//"Remove Nth Node From End of List"

//https://leetcode.com/problems/remove-nth-node-from-end-of-list


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        long long size = 1;
        ListNode* curNode = head;
        while (curNode->next) {
            curNode = curNode->next;
            size++;
        }
        if (size == n) {
            ListNode* buf = head->next;
            delete head;
            head = nullptr;
            return buf;
        }
        else {
            curNode = head;
        }
        ListNode* to_delete;
        for (long long i = 0; i < size - n-1; i++) {
            curNode = curNode->next;
        }
        to_delete = curNode->next;
        curNode->next = to_delete->next;
        delete to_delete;
        to_delete = nullptr;
        return head;
    }
};