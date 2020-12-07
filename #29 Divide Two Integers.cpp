#include <cmath>

//Divide Two Integers

//https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int dividend, int divisor) {

        double d1 = log(fabs(dividend));
        double d2 = log(fabs(divisor));

        long long res = double(exp(d1 - d2));
        if ((dividend < 0) ^ (divisor < 0)) res = -res;

        if (res > INT_MAX) return INT_MAX;
        return res;
    }
};