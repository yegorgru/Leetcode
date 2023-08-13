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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        zigzagLevelOrder(root, result, 0);
        for(size_t i = 1; i < result.size(); i+=2) {
            reverse(result[i].begin(), result[i].end());
        }
        return result;
    }

private:
    void zigzagLevelOrder(TreeNode* root, vector<vector<int>>& result, size_t currentLevel) {
        if(!root) {
            return;
        }
        if(result.size() <= currentLevel) {
            result.emplace_back();
        }
        result[currentLevel].push_back(root->val);
        zigzagLevelOrder(root->left, result, currentLevel + 1);
        zigzagLevelOrder(root->right, result, currentLevel + 1);
    }
};
