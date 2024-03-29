/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) {
            return nullptr;
        }
        auto found = mStored.find(node->val);
        if(found != mStored.end()) {
            return found->second;
        }
        Node* cloned = new Node(node->val);
        mStored[cloned->val] = cloned;
        cloned->neighbors.reserve(node->neighbors.size());
        for(auto neighbor : node->neighbors) {
            cloned->neighbors.push_back(cloneGraph(neighbor));
        }
        return cloned;
    }

private:
    map<int, Node*> mStored;
};
