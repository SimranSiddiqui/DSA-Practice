class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = dividend, b = divisor;
        long long ans = a/b;
        
        if(ans > INT_MAX)
            return INT_MAX;
        else if(ans < INT_MIN)
            return INT_MIN;
        
        return ans;
    }
};