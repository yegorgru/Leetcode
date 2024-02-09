class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 1) {
            return 1;
        }
        else if (ratings.size() == 2) {
            return ratings[0] == ratings[1] ? 2 : 3;
        }
        int result = 0;
        size_t leftIdx = 0;
        int gap = 1;
        while (leftIdx < ratings.size() - 1 && ratings[leftIdx] > ratings[leftIdx + 1]) {
            ++gap;
            ++leftIdx;
        }
        if (leftIdx == ratings.size() - 1) {
            if (ratings[leftIdx] < ratings[leftIdx - 1]) {
                ++gap;
            }
            else {
                ++result;
            }
            result += gap * (gap - 1) / 2;
            return result;
        }
        result += gap == 1 ? 0 : gap * (gap + 1) / 2 - 1;

        size_t rightIdx = ratings.size() - 1;
        gap = 1;
        while (rightIdx > 0 && ratings[rightIdx] > ratings[rightIdx - 1]) {
            ++gap;
            --rightIdx;
        }
        if (rightIdx == 0) {
            if (ratings[rightIdx] < ratings[rightIdx + 1]) {
                ++gap;
            }
            else {
                ++result;
            }
            result += gap * (gap - 1) / 2;
            return result;
        }
        result += gap == 1 ? 0 : gap * (gap + 1) / 2 - 1;
        int savedGap = 0;
        if (leftIdx == rightIdx) {
            return result + 1;
        }
        bool wasPrev = false;
        bool wasMinDup = false;

        while (leftIdx < rightIdx) {
            while (leftIdx < rightIdx && ratings[leftIdx] == ratings[leftIdx + 1]) {
                ++result;
                ++leftIdx;
            }
            if (leftIdx == rightIdx && rightIdx != ratings.size() - 1) {
                return result + 1;
            }
            gap = 1;
            while (leftIdx < rightIdx && ratings[leftIdx] < ratings[leftIdx + 1]) {
                ++gap;
                ++leftIdx;
            }
            savedGap = gap;
            result += (gap - 1) * gap / 2;
            if (leftIdx < rightIdx && ratings[leftIdx] == ratings[leftIdx + 1]) {
                result += gap;
                savedGap = 0;
                ++leftIdx;
            }
            while (leftIdx < rightIdx && ratings[leftIdx] == ratings[leftIdx + 1]) {
                ++result;
                ++leftIdx;
            }
            if (wasPrev && !wasMinDup && gap > 1) {
                --result;
            }
            gap = 1;
            while (leftIdx < rightIdx && ratings[leftIdx] > ratings[leftIdx + 1]) {
                ++gap;
                ++leftIdx;
            }
            result += (gap - 1) * gap / 2;
            result += max(gap, savedGap);
            bool wasDescGap = gap > 1;
            wasPrev = true;
            if (leftIdx < rightIdx && ratings[leftIdx] == ratings[leftIdx + 1]) {
                ++leftIdx;
                wasMinDup = true;
            }
            else {
                wasMinDup = false;
            }
            while (leftIdx < rightIdx && ratings[leftIdx] == ratings[leftIdx + 1]) {
                ++result;
                ++leftIdx;
            }
            if (leftIdx == rightIdx && (rightIdx != ratings.size() - 1 || wasDescGap) && ratings[leftIdx] == ratings[leftIdx - 1]) {
                ++result;
            }
        }
        return result;
    }
};
