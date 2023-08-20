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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(postorder.rbegin(), inorder.begin(), inorder.end());
    }
    
private:
    TreeNode* buildTree(vector<int>::reverse_iterator curr, vector<int>::const_iterator b, vector<int>::const_iterator e) {
        TreeNode* root = new TreeNode(*curr);
        auto inorderRoot = find(b, e, *curr);
        auto newMax = curr;
        root->right = buildRightSubtree(curr, next(inorderRoot), e, newMax);
        root->left = buildLeftSubtree(curr, b, inorderRoot, newMax);
        return root;
    }
    
    TreeNode* buildLeftSubtree(vector<int>::reverse_iterator parent, vector<int>::const_iterator b, vector<int>::const_iterator e, vector<int>::reverse_iterator& maximal) {
        if(e - b == 0) {
            return nullptr;
        }
        else if(e - b == 1) {
            maximal = next(maximal);
            return new TreeNode(*maximal);
        }
        else {
            auto node = new TreeNode(*next(maximal));
            auto inorderNode = find(b, e, node->val);
            auto newMax = next(maximal);
            node->right = buildRightSubtree(next(maximal), next(inorderNode), e, newMax);
            node->left = buildLeftSubtree(next(maximal), b, inorderNode, newMax);
            maximal = max(maximal, newMax);
            return node;
        }
    }
      
    TreeNode* buildRightSubtree(vector<int>::reverse_iterator parent, vector<int>::const_iterator b, vector<int>::const_iterator e, vector<int>::reverse_iterator& maximal) {
        if(e - b == 0) {
            return nullptr;
        }
        else if(e - b == 1) {
            maximal = max(maximal, next(parent));
            return new TreeNode(*next(parent));
        }
        else {
            auto node = new TreeNode(*next(parent));
            auto inorderNode = find(b, e, node->val);
            auto newMax = next(parent);
            node->right = buildRightSubtree(next(parent), next(inorderNode), e, newMax);
            node->left = buildLeftSubtree(next(parent), b, inorderNode, newMax);
            maximal = max(maximal, newMax);
            return node;
        }
    }
};
