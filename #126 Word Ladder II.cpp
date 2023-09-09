class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        auto found = find(wordList.begin(), wordList.end(), endWord);
        if (found == wordList.end()) {
            return {};
        }
        Word lastWord = make_pair(*found, NextVariants{ 0 });
        wordList.erase(found);
        Differences differences{ {lastWord} };
        differences.reserve(10);
        NextVariants beginVariants;
        while (beginVariants.size() == 0 && wordList.size() > 0) {
            DifferenceVector currDiffVector;
            for (auto it = wordList.begin(); it != wordList.end();) {
                NextVariants nextVariants;
                for (auto pIt = differences.back().begin(); pIt != differences.back().end(); ++pIt) {
                    if (findDifference(*it, pIt->first) == 1) {
                        nextVariants.push_back(pIt - differences.back().begin());
                    }
                }
                if (nextVariants.size() > 0) {
                    currDiffVector.emplace_back(make_pair(*it, std::move(nextVariants)));
                    it = wordList.erase(it);
                }
                else {
                    ++it;
                }
            }
            if (currDiffVector.size() == 0) {
                return {};
            }
            else {
                auto foundBeginWord = false;
                for (size_t i = 0; i < currDiffVector.size(); ++i) {
                    auto diffNumber = findDifference(currDiffVector[i].first, beginWord);
                    if (diffNumber == 0) {
                        beginVariants = currDiffVector[i].second;
                        foundBeginWord = true;
                        break;
                    }
                    else if (diffNumber == 1) {
                        beginVariants.push_back(i);
                    }
                }
                if(!foundBeginWord) {
                    differences.push_back(move(currDiffVector));
                }
            }
        }
        if (beginVariants.size() == 0) {
            return {};
        }
        else {
            vector<vector<string>> result;
            for (auto beginPos : beginVariants) {
                vector<string> currPath = { beginWord };
                auto nextVars = differences.back()[beginPos].second;
                findLadders(differences, differences.size() - 1, beginPos, result, currPath);
            }
            return result;
        }
    }

private:
    using NextVariants = vector<size_t>;
    using Word = pair<string, NextVariants>;
    using DifferenceVector = vector<Word>;
    using Differences = vector<DifferenceVector>;

    void findLadders(const Differences& diffs, size_t currDiffIdx, size_t currIdx, vector<vector<string>>& result, vector<string> currPath) {
        if (currDiffIdx == 0) {
            currPath.push_back(diffs[0][0].first);
            result.push_back(move(currPath));
        }
        else {
            const auto& currWord = diffs[currDiffIdx][currIdx];
            for (auto nextWord : currWord.second) {
                auto path = currPath;
                path.push_back(currWord.first);
                findLadders(diffs, currDiffIdx - 1, nextWord, result, path);
            }
        }
    }

private:
    int findDifference(const string& lhs, const string& rhs) {
        int counter = 0;
        for (size_t i = 0; i < lhs.size(); ++i) {
            counter += lhs[i] != rhs[i];
        }
        return counter;
    }
};
