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
        if(currentLevel % 2) {
            zigzagLevelOrder(root->left, result, currentLevel + 1);
            zigzagLevelOrder(root->right, result, currentLevel + 1);
        }
        else {
            zigzagLevelOrder(root->right, result, currentLevel + 1);
            zigzagLevelOrder(root->left, result, currentLevel + 1);
        }
    }
};
