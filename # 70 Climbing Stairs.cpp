class Solution {
public:
    int climbStairs(int n) {
        mSaved.fill(-1);
        if (n == 1) {
            return 1;
        }
        else {
            return climbStairs(n-1, 1) + climbStairs(n-2, 1);
        }
    }

    int climbStairs(int n, int prev) {
        if (n <= 1) {
            return prev;
        }
        else if (n == 2) {
            return 2;
        }
        else {
            if(mSaved[n] == -1) {
                mSaved[n] = prev * climbStairs(n-1, prev) + prev * climbStairs(n-2, prev);
            }
            return mSaved[n];
        }
    }

private:
    array<int, 46> mSaved;
};
