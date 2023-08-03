class Solution {
public:
    int numTrees(int n) {
        if (n == 1) {
            return 1;
        }
        if (calculated[n] != -1) {
            return calculated[n];
        }
        int counter = 2 * numTrees(n - 1);
        for (int i = 1; i < n - 1; ++i) {
            counter += numTrees(i) * numTrees(n - i - 1);
        }
        calculated[n] = counter;
        return counter;
    }

private:
    vector<int> calculated = vector<int>(20, -1);
};
