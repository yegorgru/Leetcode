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
    vector<int> inorderTraversal(TreeNode* root) {
        doInorderTraversal(root);
        return mResult;
    }

private:
    void doInorderTraversal(TreeNode* root) {
        if(root) {
            doInorderTraversal(root->left);
            mResult.push_back(root->val);
            doInorderTraversal(root->right);
        }
    }

private:
    vector<int> mResult;
};
