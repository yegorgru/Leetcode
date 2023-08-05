class Solution {
struct NumData {
    int maxDistance = 0;
    int lastFound = -1;
    int firstFound = -1;
};

public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, NumData> processingData;
        for(size_t i = 0; i < nums.size(); ++i) {
            auto& data = processingData[nums[i]];
            if(data.firstFound == -1) {
                data.firstFound = i;
            }
            else {
                int newDistance = (i - data.lastFound) / 2;
                data.maxDistance = max(newDistance, data.maxDistance);
            }
            data.lastFound = i;
        }
        int minMaxDistance = INT_MAX;
        for (auto& i : processingData) {
            auto& data = i.second;
            data.maxDistance = max((unsigned long)data.maxDistance, (data.firstFound + (nums.size() - data.lastFound)) / 2);
            minMaxDistance = min (minMaxDistance, data.maxDistance);
        }
        return minMaxDistance;
    }
};
