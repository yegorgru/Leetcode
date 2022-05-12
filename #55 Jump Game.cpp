class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> jumps(nums.size(), false);
        jumps.back() = true;
        for(int i = jumps.size() - 2; i >= 0; --i) {
            updateJump(i, nums, jumps);
        }
        return jumps[0];
    }
   
private:
    void updateJump(size_t pos, const vector<int>& nums, vector<bool>& jumps) {
        for(size_t i = std::min(pos + nums[pos], jumps.size() - 1); i != pos; --i) {
            if(jumps[i]) {
                jumps[pos] = true;
                return;
            }
        }
    }
};
