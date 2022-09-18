class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum =0;
        int pro = 1;
        while(n)
        {
         int x = n%10;
            sum+=x;
            pro*=x;
            n/=10;
        }
        
        return pro-sum;
    }
};