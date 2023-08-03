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
    void recoverTree(TreeNode* root) {
        mRoot = root;
        findToRecover(root);
        tryRecover(root);
    }

private:
    void findToRecover(TreeNode* root) {
        if(found || !root) {
            return;
        }
        toRecover = root;
        tryRecover(mRoot);
        if (root->left) {
            findToRecover(root->left);
        }
        if (root->right) {
            findToRecover(root->right);
        }
    }

    void tryRecover(TreeNode* root) {
        if(found || !root) {
            return;
        }
        swap(toRecover->val, root->val);
        if(isValidBST(mRoot)) {
            found = true;
        }
        if(!found) {
            swap(toRecover->val, root->val);
            if (root->left) {
                tryRecover(root->left);
            }
            if (root->right) {
                tryRecover(root->right);
            }
        }
    }

private:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullopt, nullopt);
    }

    bool isValidBST(TreeNode* root, optional<int> minimal, optional<int> maximal) {
        if(!root) {
            return true;
        }
        bool isValid = true;
        if(root->left) {
            isValid = isValidBST(root->left, minimal, root->val);
        }
        if(isValid && root->right) {
            isValid = isValidBST(root->right, root->val, maximal);
        }
        if(isValid && minimal != nullopt) {
            isValid = root->val > minimal;
        }
        if(isValid && maximal != nullopt) {
            isValid = root->val < maximal;
        }
        return isValid;
    }

private:
    TreeNode* mRoot = nullptr;
    TreeNode* toRecover = nullptr;
    bool found = false;
};
