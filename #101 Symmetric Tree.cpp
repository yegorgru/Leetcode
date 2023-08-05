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
    bool isSymmetric(TreeNode* root) {
        return isSymmetricBranches(root->left, root->right);
    }

private:
    bool isSymmetricBranches(TreeNode* left, TreeNode* right) {
        if(left && !right || right && !left) {
            return false;
        }
        else if(!left && !right) {
            return true;
        }
        else {
            return left->val == right->val && 
                isSymmetricBranches(left->left, right->right) &&
                isSymmetricBranches(left->right, right->left);
        }
    }
};
