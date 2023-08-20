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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums.begin(), nums.end());
    }
    
private:
    TreeNode* sortedArrayToBST(vector<int>::iterator b, vector<int>::iterator e) {
        if(e - b < 1) {
            return nullptr;
        }
        auto middle = b + (e - b) / 2;
        auto node = new TreeNode(*middle);
        node->left = sortedArrayToBST(b, middle);
        node->right = sortedArrayToBST(next(middle), e);
        return node;
    }
};
