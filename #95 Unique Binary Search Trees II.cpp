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
    vector<TreeNode*> generateTrees(int n) {
        vector<int> permutation(n, 0);
        iota(permutation.begin(), permutation.end(), 1);
        vector<vector<int>> permutations {permutation};
        while(next_permutation(permutation.begin(), permutation.end())) {
            permutations.push_back(permutation);
        }
        vector<TreeNode*> result;
        result.reserve(permutations.size());
        for (const auto& v : permutations) {
            vector<int> arr(256, 0);
            arr[0] = v[0];
            for (size_t i = 1; i < v.size(); ++i) {
                insertValue(arr, 0, v[i]);
            }
            if(stored.find(arr) == stored.end()) {
                stored.insert(arr);
                TreeNode* root = new TreeNode(v[0]);
                for (size_t i = 1; i < v.size(); ++i) {
                    insertValue(root, v[i]);
                }
                result.push_back(root);
            }
        }
        return result;
    }

private:
    void insertValue(TreeNode* node, int value) {
        if(value < node->val) {
            if(node->left) {
                insertValue(node->left, value);
            }
            else {
                node->left = new TreeNode(value);
            }
        }
        else {
            if(node->right) {
                insertValue(node->right, value);
            }
            else {
                node->right = new TreeNode(value);
            }
        }
    }

    void insertValue(vector<int>& arr, int idx, int value) {
        if(value < arr[idx]) {
            if(arr[idx * 2 + 1] != 0) {
                insertValue(arr, idx * 2 + 1, value);
            }
            else {
                arr[idx * 2 + 1] = value;
            }
        }
        else {
            if(arr[idx * 2 + 2] != 0) {
                insertValue(arr, idx * 2 + 2, value);
            }
            else {
                arr[idx * 2 + 2] = value;
            }
        }
    }

private:
    set<vector<int>> stored;
};
