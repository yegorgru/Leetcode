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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullopt, nullopt);
    }

private:
    bool isValidBST(TreeNode* root, optional<int> minimal, optional<int> maximal) {
        if(!root) {
            return true;
        }
        bool isValid = true;
        if(root->left) {
            isValid = isValidBST(root->left, minimal, root->val);
        }
        if(isValid && root->right) {
            isValid = isValidBST(root->right, root->val, maximal);
        }
        if(isValid && minimal != nullopt) {
            isValid = root->val > minimal;
        }
        if(isValid && maximal != nullopt) {
            isValid = root->val < maximal;
        }
        return isValid;
    }
};
