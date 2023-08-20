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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int counter = 0;
        auto headCopy = head;
        while(head) {
            head = head->next;
            ++counter;
        }
        return sortedListToBST(headCopy, head, counter);
    }
    
private:
    TreeNode* sortedListToBST(ListNode* b, ListNode* e, int size) {
        if(!b || size < 1) {
            return nullptr;
        }
        auto bCopy = b;
        for(int i = 0; i < size / 2; ++i) {
            b = b->next;
        }
        int counter = 0;
        auto bCounter = b->next;
        while(bCounter != e) {
            bCounter = bCounter->next;
            ++counter;
        }
        auto rightHead = b->next;
        auto node = new TreeNode(b->val);
        node->left = sortedListToBST(bCopy, b, size / 2);
        if(rightHead != e) {
            node->right = sortedListToBST(rightHead, e, counter);   
        }
        return node;
    }
};
