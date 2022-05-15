class Solution {
public:   
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0) {
            return {newInterval};
        }
        if(newInterval[0] > intervals.back()[1]) {
            intervals.push_back(newInterval);
            return intervals;
        }
        else if(newInterval[1] < intervals.front()[0]) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        else if(newInterval[1] <= intervals.front()[1]) {
            intervals.front()[0] = min(newInterval[0], intervals.front()[0]);
            return intervals;
        }
        if(newInterval[0] < intervals.front()[0]) {
            intervals.front()[0] = newInterval[0];
        }
        auto lower = upper_bound(intervals.begin(), intervals.end(), newInterval,
          [](const vector<int>& lhs, const vector<int>& rhs){
              return lhs[0] < rhs[0];
          });
        auto upper = upper_bound(intervals.begin(), intervals.end(), newInterval,
          [](const vector<int>& lhs, const vector<int>& rhs){
              return lhs[1] < rhs[0];
          });
        if((*prev(lower))[0] <= newInterval[0] && newInterval[0] <= (*prev(lower))[1]) {
            newInterval[0] = (*prev(lower))[0];
            lower = prev(lower);
        }
        if((*prev(upper))[0] <= newInterval[1] && newInterval[1] <= (*prev(upper))[1]) {
            newInterval[1] = (*prev(upper))[1];
        }
        size_t pos = lower - intervals.begin();
        intervals.erase(lower, upper);
        intervals.insert(intervals.begin() + pos, newInterval);
        return intervals;
    }
};
