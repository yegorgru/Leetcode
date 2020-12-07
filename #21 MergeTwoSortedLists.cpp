
//Merge Two Sorted Lists

//https://leetcode.com/problems/merge-two-sorted-lists/

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
  class Solution {
  public:
      ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
          ListNode* prev = nullptr;
          ListNode* answer = nullptr;
          while (l1 != nullptr || l2 != nullptr) {
              ListNode* cur = new ListNode;
              if (l1 == nullptr) {
                  cur->val = l2->val;
                  l2 = l2->next;
              }
              else if (l2 == nullptr) {
                  cur->val = l1->val;
                  l1 = l1->next;
              }
              else if (l1->val < l2->val) {
                  cur->val = l1->val;
                  l1 = l1->next;
              }
              else {
                  cur->val = l2->val;
                  l2 = l2->next;
              }
              if (prev == nullptr) {
                  answer = cur;
              }
              if (prev != nullptr) {
                  prev->next = cur;
              }
              prev = cur;
          }
          return answer;
      }
  };

  int main() {
      ListNode* a3 = new ListNode(4);
      ListNode* a2 = new ListNode(2,a3);
      ListNode* a1 = new ListNode(1, a2);

      ListNode* b3 = new ListNode(4);
      ListNode* b2 = new ListNode(3, b3);
      ListNode* b1 = new ListNode(1, b2);

      Solution sol;
      auto res = sol.mergeTwoLists(a1, a2);
  }