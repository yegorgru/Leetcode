class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto found = find(wordList.begin(), wordList.end(), endWord);
        if (found == wordList.end()) {
            return 0;
        }
        if(findDifference(beginWord, endWord) == 1) {
            return 2;
        }
        wordList.erase(found);
        Differences differences{ {endWord} };
        differences.reserve(10);
        bool foundBeginWord = false;
        while (!foundBeginWord && wordList.size() > 0) {
            DifferenceVector currDiffVector;
            for (auto it = wordList.begin(); it != wordList.end();) {
                int counter = 0;
                for (auto pIt = differences.back().begin(); pIt != differences.back().end(); ++pIt) {
                    if (findDifference(*it, *pIt) == 1) {
                        ++counter;
                    }
                }
                if (counter > 0) {
                    currDiffVector.emplace_back(*it);
                    it = wordList.erase(it);
                }
                else {
                    ++it;
                }
            }
            if (currDiffVector.size() == 0) {
                return 0;
            }
            else {
                for (size_t i = 0; i < currDiffVector.size(); ++i) {
                    auto diffNumber = findDifference(currDiffVector[i], beginWord);
                    if (diffNumber == 0) {
                        return differences.size() + 1;
                    }
                    else if (diffNumber == 1) {
                        foundBeginWord = true;
                    }
                }
                differences.push_back(move(currDiffVector));
            }
        }
        if (!foundBeginWord) {
            return 0;
        }
        else {
            return differences.size() + 1;
        }
    }

private:
    using DifferenceVector = vector<string>;
    using Differences = vector<DifferenceVector>;

private:
    int findDifference(const string& lhs, const string& rhs) {
        int counter = 0;
        for (size_t i = 0; i < lhs.size(); ++i) {
            counter += lhs[i] != rhs[i];
        }
        return counter;
    }
};
