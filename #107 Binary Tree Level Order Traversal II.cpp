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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        levelOrderBottom(root, result, 0);
        reverse(result.begin(), result.end());
        return result;
    }

private:
    void levelOrderBottom(TreeNode* root, vector<vector<int>>& result, size_t currentLevel) {
        if(!root) {
            return;
        }
        if(result.size() <= currentLevel) {
            result.emplace_back();
        }
        result[currentLevel].push_back(root->val);
        levelOrderBottom(root->left, result, currentLevel + 1);
        levelOrderBottom(root->right, result, currentLevel + 1);
    }
};
