class Solution {
public:
    int mySqrt(int x) {
        int lower = 0;
        int upper = 46340;
        if(x >= upper * upper) {
            return upper;
        }
        while (true) {
            int checked = (lower + upper) / 2;
            if (checked * checked <= x && (checked + 1) * (checked + 1) > x) {
                return checked;
            }
            else if(checked * checked > x) {
                upper = checked;
            }
            else {
                lower = checked;
            }
        }
    }
};
