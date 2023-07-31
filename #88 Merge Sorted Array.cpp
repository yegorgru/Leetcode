class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1Cp(nums1.begin(), nums1.begin() + m);
        int i = 0;
        int j = 0;
        int currIdx = 0;
        while(i < m && j < n) {
            if(nums1Cp[i] < nums2[j]) {
                nums1[currIdx++] = nums1Cp[i++];
            }
            else {
                nums1[currIdx++] = nums2[j++];
            }
        }
        while(i < m) {
            nums1[currIdx++] = nums1Cp[i++];
        }
        while(j < n) {
            nums1[currIdx++] = nums2[j++];
        }
    }
};
