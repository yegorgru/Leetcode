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
    void flatten(TreeNode* root) {
        flattenHelper(root);
    }
    
private:
    pair<TreeNode*, TreeNode*> flattenHelper(TreeNode* root) {
        if(!root) {
            return make_pair(nullptr, nullptr);
        }
        else if(!root->left && !root->right) {
            return make_pair(root, root);
        }
        else if(root->left && root->right) {
            auto left = root->left;
            auto right = root->right;
            auto flattenLeft = flattenHelper(left);
            auto flattenRight = flattenHelper(right);
            root->left = nullptr;
            root->right = flattenLeft.first;
            flattenLeft.second->right = flattenRight.first;
            return make_pair(root, flattenRight.second);
        }
        else if(root->left) {
            auto left = root->left;
            auto flattenLeft = flattenHelper(left);
            root->left = nullptr;
            root->right = flattenLeft.first;
            return make_pair(root, flattenLeft.second);
        }
        else {
            auto right = root->right;
            auto flattenRight = flattenHelper(right);
            root->left = nullptr;
            root->right = flattenRight.first;
            return make_pair(root, flattenRight.second);
        }
    }
};
