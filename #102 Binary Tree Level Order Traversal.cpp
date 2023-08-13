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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelOrder(root, result, 0);
        return result;
    }

private:
    void levelOrder(TreeNode* root, vector<vector<int>>& result, size_t currentLevel) {
        if(!root) {
            return;
        }
        if(result.size() <= currentLevel) {
            result.emplace_back();
        }
        result[currentLevel].push_back(root->val);
        levelOrder(root->left, result, currentLevel + 1);
        levelOrder(root->right, result, currentLevel + 1);
    }
};
