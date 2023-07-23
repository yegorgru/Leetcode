class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size();
        int n = matrix.size();
        int leftBound = 0;
        int rightBound = m * n;
        while (rightBound - leftBound > 1) {
            int currentIdx = (leftBound + rightBound - 1) / 2;
            int current = matrix[currentIdx / m][currentIdx % m];
            if (current == target) {
                return true;
            }
            else if (current > target) {
                rightBound = currentIdx;
            }
            else {
                leftBound = currentIdx + 1;
            }
        }
        return leftBound < m * n ? matrix[leftBound / m][leftBound % m] == target : false;
    }
};
