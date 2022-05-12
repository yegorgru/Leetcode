struct Interval{
    int x;
    int y;
};

struct IntervalNode;
using NodePtr = shared_ptr<IntervalNode>;

struct IntervalNode {
    IntervalNode(Interval interval) : interval(interval) {}
    
    Interval interval;
    NodePtr left = nullptr;
    NodePtr right = nullptr;
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        NodePtr root(new IntervalNode({intervals[0][0], intervals[0][1]}));
        set<int> points;
        for(size_t i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] == intervals[i][1]) {
                points.insert(intervals[i][0]);
            }
            else {
                merge(Interval{intervals[i][0], intervals[i][1]}, root);   
            }
        }
        vector<vector<int>> answer;
        answer.reserve(intervals.size());
        leftWalk(root, answer);
        for(auto point : points) {
            if(!findPoint(point, root)) {
                answer.push_back({point, point});
            }
        }
        return answer;
    }
    
private:
    bool findPoint(int point, NodePtr node) {
        if(point >= node->interval.x && point <= node->interval.y) {
            return true;
        }
        if(point < node->interval.x && node->left) {
            return findPoint(point, node->left);
        }
        else if(point > node->interval.y && node->right) {
            return findPoint(point, node->right);
        }
        return false;
    }
    
    void leftWalk(NodePtr node, vector<vector<int>>& answer) {
        if(!node) return;
        leftWalk(node->left, answer);
        answer.push_back({node->interval.x, node->interval.y});
        leftWalk(node->right, answer);
    }
    
    void merge(Interval interval, NodePtr node) {
        if(interval.x <= node->interval.y && interval.y > node->interval.y) {
            node->interval.y = interval.y;
            expandRight(node->right, node);
        }
        if(interval.y >= node->interval.x && interval.x < node->interval.x) {
            node->interval.x = interval.x;
            expandLeft(node->left, node);
        }
        else if(node->interval.y < interval.x) {
            if(node->right) {
                merge(interval, node->right); 
            }
            else {
                node->right = NodePtr(new IntervalNode(interval));
            }
        }
        else if(node->interval.x > interval.y) {
            if(node->left) {
               merge(interval, node->left); 
            }
            else {
                node->left = NodePtr(new IntervalNode(interval));
            }
        }
    }
    
    void expandRight(NodePtr node, NodePtr parent) {
        if(node && parent->interval.y >= node->interval.x) {
            if(parent->interval.y <= node->interval.y) {
                parent->interval.y = node->interval.y;
            }
            expandRight(node->right, parent);
        }
        else {
            if(node) {
                node->left = updateY(node->left, parent);   
            }
            parent->right = node;
        }
    }
    
    NodePtr updateY(NodePtr node, NodePtr expanded) {
        if(node && expanded->interval.y >= node->interval.x) {
            expanded->interval.y = max(node->interval.y,  expanded->interval.y);
            return updateY(node->right, expanded);
        }
        else if(node) {
            node->left = updateY(node->left, expanded);
        }
        return node;
    }
    
    void expandLeft(NodePtr node, NodePtr parent) {
        if(node && parent->interval.x <= node->interval.y) {
            if(parent->interval.x >= node->interval.x) {
                parent->interval.x = node->interval.x;
            }
            expandLeft(node->left, parent);
        }
        else {
            if(node) {
                node->right = updateX(node->right, parent);   
            }
            parent->left = node;
        }
    }
    
    NodePtr updateX(NodePtr node, NodePtr expanded) {
        if(node && expanded->interval.x <= node->interval.y) {
            expanded->interval.x = min(node->interval.x, expanded->interval.x);
            return updateX(node->left, expanded);
        }
        else if(node) {
            node->right = updateX(node->right, expanded);
        }
        return node;
    }
};
