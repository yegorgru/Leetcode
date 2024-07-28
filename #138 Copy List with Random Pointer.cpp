/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        auto headCopy = head;
        std::map<Node*, Node*> nodesMap;
        Node* prev = nullptr;
        Node* newNodesHeadCopy = nullptr;
        while(head) {
            auto newNode = new Node(head->val);
            if(!newNodesHeadCopy) {
                newNodesHeadCopy = newNode;
            }
            nodesMap[head] = newNode;
            if(prev) {
                prev->next = newNode;
            }
            
            prev = newNode;
            head = head->next;
        }

        head = headCopy;
        auto newNodesHead = newNodesHeadCopy;
        while(head) {
            newNodesHead->random = nodesMap[head->random];    
                    
            head = head->next;
            newNodesHead = newNodesHead->next;
        }

        return newNodesHeadCopy;
    }
};
