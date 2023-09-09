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
    int maxPathSum(TreeNode* root) {
        maxPathSum(root, 0);
        return mMaxSum;
    }

private:
    optional<int> maxPathSum(TreeNode* root, int currSum) {
        if (!root) {
            return nullopt;
        }
        auto leftSum = maxPathSum(root->left, 0);
        auto rightSum = maxPathSum(root->right, 0);
        int maxViaCenter = (leftSum ? *leftSum : 0) + root->val + (rightSum ? *rightSum : 0);
        mMaxSum = max(mMaxSum, maxViaCenter);
        mMaxSum = max(mMaxSum, root->val);
        mMaxSum = max(mMaxSum, (leftSum ? *leftSum : mMaxSum));
        mMaxSum = max(mMaxSum, (rightSum ? *rightSum : mMaxSum));
        mMaxSum = max(mMaxSum, (leftSum ? *leftSum + root->val : mMaxSum));
        mMaxSum = max(mMaxSum, (rightSum ? *rightSum + root->val : mMaxSum));
        return max(max((leftSum ? *leftSum : 0) + root->val, (rightSum ? *rightSum : 0) + root->val), root->val);
    }
private:
    int mMaxSum = INT_MIN;
};
