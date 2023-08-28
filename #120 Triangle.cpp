class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        mMinLengths.resize(triangle.size(), vector<int>(triangle.back().size(), INT_MAX));
        return minimumTotal(triangle, 0, 0);
    }

private:
    int minimumTotal(const vector<vector<int>>& triangle, size_t currRow, size_t currIdx) {
        if (currRow == triangle.size() - 1) {
            return triangle[currRow][currIdx];
        }
        else if (mMinLengths[currRow][currIdx] != INT_MAX) {
            return mMinLengths[currRow][currIdx];
        }
        else {
            int currMin = min(
                minimumTotal(triangle, currRow + 1, currIdx),
                minimumTotal(triangle, currRow + 1, currIdx + 1)
            );
            mMinLengths[currRow][currIdx] = currMin + triangle[currRow][currIdx];
            return mMinLengths[currRow][currIdx];
        }
    }

private:
    vector<vector<int>> mMinLengths;
};
