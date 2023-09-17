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
    int sumNumbers(TreeNode* root) {
        sumNumbers(root, 0);
        return mSum;
    }

private:
    void sumNumbers(TreeNode* node, int currSum) {
        bool wasChild = false;
        currSum = currSum * 10 + node->val;
        if(node->left) {
            sumNumbers(node->left, currSum);
            wasChild = true;
        }
        if(node->right) {
            sumNumbers(node->right, currSum);
            wasChild = true;
        }
        if(!wasChild) {
            mSum += currSum;
        }
    }

private:
    int mSum = 0;
};
