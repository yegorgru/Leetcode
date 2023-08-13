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
    int maxDepth(TreeNode* root) {
        maxDepth(root, 1);
        return mMaxDepth;
    }

private:
    void maxDepth(TreeNode* root, int currLevel) {
        if(!root) {
            return;
        }
        mMaxDepth = max(mMaxDepth, currLevel);
        maxDepth(root->left, currLevel + 1);
        maxDepth(root->right, currLevel + 1);
    }

private:
    int mMaxDepth = 0;
};
