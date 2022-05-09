class Solution {
public:
    double powHelper(double x, int n) {
        if(n == 0) {
            return 1.0;
        }
        double part = powHelper(x, n/2);
        part *= part;
        if(n % 2 == 1) {
            part *= x;
        }
        return part;
    }
    
    double myPow(double x, int n) {
        if(x == 1.0) {
            return x;
        }
        if(x == -1.0) {
            if(n % 2 == 0) {
                return 1.0;   
            }
            else {
                return -1.0;
            }
        }
        if(n == -2147483648) {
            return 0.0;
        }
        else if(n < 0) {
            return 1.0 / powHelper(x, abs(n));
        }
        else {
            return powHelper(x, abs(n));
        }
    }
};
