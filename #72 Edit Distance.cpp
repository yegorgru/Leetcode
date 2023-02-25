class Solution {
public:
    int minDistance(string word1, string word2) {
        mCache.resize(word1.size(), vector<int>(word2.size(), 1000));
        return minDistanceRef(word1, word2, word1.size() - 1, word2.size() - 1);
    }

private:
    int minDistanceRef(string& word1, string& word2, int firstIndex, int secondIndex) {
        if (firstIndex < 0) {
            return secondIndex + 1;
        }
        else if (secondIndex < 0) {
            return firstIndex + 1;
        }
        if (mCache[firstIndex][secondIndex] != 1000) {
            return mCache[firstIndex][secondIndex];
        }
        for (int i = firstIndex, j = secondIndex; i >= 0 && j >= 0; --i, --j) {
            if (word1[i] != word2[j]) {
                auto minimal = min({ minDistanceRef(word1, word2, i, j - 1),
                                    minDistanceRef(word1, word2, i - 1, j),
                                    minDistanceRef(word1, word2, i - 1, j - 1) }) + 1;
                mCache[firstIndex][secondIndex] = minimal;
                return minimal;
            }
        }
        mCache[firstIndex][secondIndex] = max(firstIndex, secondIndex) - min(firstIndex, secondIndex);
        return mCache[firstIndex][secondIndex];
    }

private:
    vector<vector<int>> mCache;
};
