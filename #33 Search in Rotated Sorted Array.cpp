class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() < 10) {
            auto it = std::find(nums.begin(), nums.end(), target);
            if(it == nums.end()) return -1;
            return it-nums.begin();
        }
        int pivot = nums.back();
        size_t bottom = 0;
        size_t top = nums.size()-2;
        while(true){
            if(top - bottom == 1 && nums[bottom] > nums[top]) break;
            size_t newPos = (top+bottom)/2;
            if(nums[newPos] > pivot) bottom = newPos;
            else top = newPos;
        }
        int s = binarySearch(nums, target, 0, top);
        if(s == -1) return binarySearch(nums, target, top, nums.size());
        else return s;
    }
    
private:
    int binarySearch(vector<int>& nums, int target, size_t bottom, size_t top){
        size_t pos = (top+bottom)/2;
        while(true){
            if(nums[pos] == target) return pos;
            if(top - bottom == 1) return -1;
            else if(nums[pos] < target){
                bottom = pos;
            }
            else{
                top = pos;
            }
            pos = (top+bottom)/2;
        }
    }
};