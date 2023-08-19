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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder.begin(), inorder.begin(), inorder.end());
    }
    
private:
    TreeNode* buildTree(vector<int>::const_iterator curr, vector<int>::const_iterator b, vector<int>::const_iterator e) {
        TreeNode* root = new TreeNode(*curr);
        auto inorderRoot = find(b, e, *curr);
        auto newMax = curr;
        root->left = buildLeftSubtree(curr, b, inorderRoot, newMax);
        root->right = buildRightSubtree(curr, next(inorderRoot), e, newMax);
        return root;
    }
    
    TreeNode* buildLeftSubtree(vector<int>::const_iterator parent, vector<int>::const_iterator b, vector<int>::const_iterator e, vector<int>::const_iterator& maximal) {
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
            node->left = buildLeftSubtree(next(parent), b, inorderNode, newMax);
            node->right = buildRightSubtree(next(parent), next(inorderNode), e, newMax);
            maximal = max(maximal, newMax);
            return node;
        }
    }
      
    TreeNode* buildRightSubtree(vector<int>::const_iterator parent, vector<int>::const_iterator b, vector<int>::const_iterator e, vector<int>::const_iterator& maximalLeft) {
        if(e - b == 0) {
            return nullptr;
        }
        else if(e - b == 1) {
            maximalLeft = next(maximalLeft);
            return new TreeNode(*maximalLeft);
        }
        else {
            auto node = new TreeNode(*next(maximalLeft));
            auto inorderNode = find(b, e, node->val);
            auto newMax = next(maximalLeft);
            node->left = buildLeftSubtree(next(maximalLeft), b, inorderNode, newMax);
            node->right = buildRightSubtree(next(maximalLeft), next(inorderNode), e, newMax);
            maximalLeft = max(maximalLeft, newMax);
            return node;
        }
    }
};
