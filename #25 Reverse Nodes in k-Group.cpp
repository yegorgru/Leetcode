#include <stack>
#include <iostream>

//Reverse Nodes in k-Group

//https://leetcode.com/problems/reverse-nodes-in-k-group/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* res = head;
        ListNode* first_turn = nullptr;
        while (head) {
            std::stack<int>st;
            first_turn = head;
            for (int i = 0; i < k; i++) {
                if (first_turn) {
                    st.push(first_turn->val);
                    first_turn = first_turn->next;
                }
                else {
                    return res;
                }
            }
            for (int i = 0; i < k; i++) {
                head->val = st.top();
                st.pop();
                head = head->next;
            }
        }
        return res;
    }
};