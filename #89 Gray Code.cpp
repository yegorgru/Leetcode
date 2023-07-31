class Solution {
public:
    vector<int> grayCode(int n) {
        int maxN = pow(2, n);
        vector<int> res;
        res.reserve(maxN);
        for(int i = 0; i < maxN; ++i) {
            res.push_back(nextGreyCode(i));
        }
        return res;
    }

private:
    int nextGreyCode(int num) {
        return num ^ (num >> 1);
    }
};
