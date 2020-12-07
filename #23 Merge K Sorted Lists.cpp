#include <vector>
#include <iostream>

//Merge k Sorted Lists

//https://leetcode.com/problems/merge-k-sorted-lists/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        ListNode* prev = nullptr;
        ListNode* answer = nullptr;
        while (true) {
            int min = 0;
            size_t min_pos = 0;
            bool was_min = false;
            for (size_t i = 0; i < lists.size(); i++) {
                if (!was_min && lists[i] != nullptr) {
                    min = lists[i]->val;
                    was_min = true;
                    min_pos = i;
                }
                else  if (lists[i]!= nullptr && lists[i]->val < min) {
                    min = lists[i]->val;
                    min_pos = i;
                }
            }
            if (!was_min) {
                return answer;
            }
            else {
                ListNode* cur = new ListNode(min);
                lists[min_pos] = lists[min_pos]->next;
                if (prev == nullptr) {
                    answer = cur;
                }
                if (prev != nullptr) {
                    prev->next = cur;
                }
                prev = cur;
            }
        }
        return answer;
    }
};

int main() {
    ListNode* a3 = new ListNode(5);
    ListNode* a2 = new ListNode(4, a3);
    ListNode* a1 = new ListNode(1, a2);

    ListNode* b3 = new ListNode(4);
    ListNode* b2 = new ListNode(3, b3);
    ListNode* b1 = new ListNode(1, b2);

    ListNode* c2 = new ListNode(6);
    ListNode* c1 = new ListNode(2, c2);

    std::vector<ListNode*>v = { a1,b1,c1 };

    Solution sol;
    auto res = sol.mergeKLists(v);

    while (res != nullptr) {
        std::cout << res->val;
        res = res->next;
    }
}