class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> smaller;
        smaller.push(0);
        for(int i = 1; i < heights.size(); ++i) {
            if (heights[i] >= heights[i - 1]) {
                smaller.push(i);
            }
            else {
                while (smaller.size() > 1 && heights[smaller.top()] > heights[i]) {
                    maxArea = max(maxArea, (i - smaller.top()) * heights[smaller.top()]);
                    smaller.pop();
                }
                while (smaller.size() > 0) {
                    maxArea = max(maxArea, evaluateSideArea(heights, smaller.top()));
                    smaller.pop();
                }   
                smaller.push(i);
            }
        }
        while (smaller.size() > 1) {
            maxArea = max(maxArea, ((int)heights.size() - smaller.top()) * heights[smaller.top()]);
            smaller.pop();
        }
        maxArea = max(maxArea, evaluateSideArea(heights, smaller.top()));  
        return maxArea;
    }

private:
    int evaluateSideArea(const vector<int>& heights, int idx) {
        if ((int)heights.size() * heights[idx] < maxArea) {
            return 0;
        }
        int currIdx = idx - 1;
        int leftArea = 0;
        while (currIdx >= 0) {
            if (heights[currIdx] < heights[idx]) {
                break;
            }
            ++leftArea;
            --currIdx;
        }
        currIdx = idx + 1;
        int rightArea = 0;
        while (currIdx < heights.size()) {
            if (heights[currIdx] < heights[idx]) {
                break;
            }
            ++rightArea;
            ++currIdx;
        }
        return heights[idx] * (leftArea + rightArea + 1);
    }

private:
    int maxArea = INT_MIN;
};
