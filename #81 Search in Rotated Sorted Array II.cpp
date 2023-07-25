class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() < 10) {
            return std::find(nums.begin(), nums.end(), target) != nums.end();
        }
        pivot = nums.back();
        size_t bottom = 0;
        size_t top = nums.size()-2;
        top = pivotSearch(nums, bottom, top);
        int s = binarySearch(nums, target, 0, top);
        if(s == -1) return binarySearch(nums, target, top, nums.size()) != -1;
        else return true;
    }
    
private:
    int pivotSearch(vector<int>& nums, size_t bottom, size_t top) {
        while(true){
            if(top - bottom == 1) {
                if(nums[bottom] > nums[top]) {
                    return top;
                }
                else {
                    return -1;
                }
            }
            size_t newPos = (top+bottom)/2;
            if(nums[newPos] > pivot) {
                bottom = newPos;
            }
            else if (pivot > nums[newPos]) {
                top = newPos;
            }
            else {
                int res = pivotSearch(nums, newPos, top);
                return res != -1 ? res : pivotSearch(nums, bottom, newPos);
            }
        }
    }

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

private:
    int pivot = 0;
};
