#include <vector>
#include <iostream>
#include <algorithm>
#include "Header.h"
using namespace std;

//"Median of two sorted arrays"

//https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int>merged(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());

        size_t median = (nums1.size() + nums2.size()) / 2;
        if ((nums1.size() + nums2.size())%2 == 0) {
            return (merged[median] + merged[median - 1]) / 2.0;
        }
        else {
            return merged[median];
        }
    }
};

void Test(){
    Solution s;
    {
        vector<int> a{ };
        vector<int> b{ 1 };
        AssertEqual(s.findMedianSortedArrays(a, b), 1);
    }
    {
        vector<int> a{ 1 };
        vector<int> b{ };
        AssertEqual(s.findMedianSortedArrays(a, b), 1);
    }
    {
        vector<int> a{ 1 };
        vector<int> b{2 };
        AssertEqual(s.findMedianSortedArrays(a, b), 1.5);
    }
    {
        vector<int> a{ 1, 3 };
        vector<int> b{ 2 };
        AssertEqual(s.findMedianSortedArrays(a, b), 2);
    }
    {
        vector<int> a{ 1,2, 3 };
        vector<int> b{ 0 };
        AssertEqual(s.findMedianSortedArrays(a, b), 1.5);
    }
    {
        vector<int> a{ 1, 2 };
        vector<int> b{ 3,4 };
        AssertEqual(s.findMedianSortedArrays(a, b), 2.5);
    }
    {
        vector<int> a{ 1, 3 };
        vector<int> b{ 2 };
        AssertEqual(s.findMedianSortedArrays(a, b), 2);
    }
    {
        vector<int> a{ 0, 0 };
        vector<int> b{ 0 };
        AssertEqual(s.findMedianSortedArrays(a, b), 0);
    }
    {
        vector<int> a{ 0, 0 };
        vector<int> b{ 0,0 };
        AssertEqual(s.findMedianSortedArrays(a, b), 0);
    }
    
}

int main() {   
    TestRunner tr;
    RUN_TEST(tr, Test);
}