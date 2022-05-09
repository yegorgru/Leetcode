class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> jumps(nums.size(), std::numeric_limits<int>::max());
        jumps.back() = 0;
        for(int i = jumps.size() - 2; i >= 0; --i) {
            updateJump(i, nums, jumps);
        }
        return jumps[0];
    }
   
private:
    void updateJump(size_t pos, const vector<int>& nums, vector<int>& jumps) {
        for(size_t i = std::min(pos + nums[pos], jumps.size() - 1); i != pos; --i) {
            if(jumps[i] == std::numeric_limits<int>::max()) {
                continue;
            }
            int nextValue = jumps[i] + 1;
            if(jumps[pos] > nextValue) {
                jumps[pos] = nextValue;
            }
        }
    }
};
