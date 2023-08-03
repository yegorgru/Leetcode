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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p && !q || !p && q) {
            return false;
        }
        else if(!p && !q) {
            return true;
        }
        else {
            if (p->val != q->val) {
                return false;
            }
            if((p->left || q->left) && !isSameTree(p->left, q->left)) {
                return false;
            }
            if((p->right || q->right) && !isSameTree(p->right, q->right)) {
                return false;
            }
            return true;
        }
    }
};
