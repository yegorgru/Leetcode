/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        connect(root, 0);
        return root;
    }
    
private:
    void connect(Node* node, int level) {
        if(!node) {
            return;
        }
        if(mNodes.size() < level + 1) {
            mNodes.resize(level + 1, node);
        }
        else {
            mNodes[level]->next = node;
            mNodes[level] = node;
        }
        connect(node->left, level + 1);
        connect(node->right, level + 1);
    }
    
private:
    vector<Node*> mNodes;
};
