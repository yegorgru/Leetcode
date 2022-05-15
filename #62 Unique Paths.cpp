class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> computed(m - 1, vector<int>(n, -1));
        for(auto& i : computed) {
            i.back() = 1;
        }
        computed.push_back(vector<int>(n, 1));
        for(int i = m - 2; i >= 0; i--) {
            for(int j = n - 2; j >= 0; j--) {
                computed[i][j] = computed[i+1][j] + computed[i][j+1];
            }
        }
        return computed[0][0];
    }
};
