class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits.back()++;
        for(auto it = digits.rbegin(); it < digits.rend(); ++it) {
            if(*it == 10) {
                *it = 0;
                if(next(it) != digits.rend()) {
                    (*next(it))++;
                }
                else {
                    digits.insert(digits.begin(), 1);
                    return digits;
                }
            }
            else {
                return digits;
            }
        }
        return digits;
    }
};
