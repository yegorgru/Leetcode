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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        pathSum(root, targetSum, path);
        return result;
    }
    
private:
    void pathSum(TreeNode* node, int targetSum, vector<int>& currPath) {
        if(!node) {
            return;
        }
        if(!node->left && !node->right) {
            if(node->val == targetSum) {
                auto foundPath = currPath;
                foundPath.push_back(node->val);
                result.push_back(foundPath);
            }
            return;
        }
        currPath.push_back(node->val);
        pathSum(node->left, targetSum - node->val, currPath);
        pathSum(node->right, targetSum - node->val, currPath);
        currPath.pop_back();
    }
private:
    vector<vector<int>> result;
};
