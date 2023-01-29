class Solution {
    #define MOD 1000000007
    
    int calPower(int n)
    {
        if(n <= 0)
            return 1;
        if(n == 1)
            return 2;
        
        long long ans = calPower(n/2)%MOD;
        
        if(n%2 == 0)
            return (ans*ans)%MOD; 
        else
            return (ans * ans *2)%MOD;
        
    }
public:
    int monkeyMove(int n) {
        
      int ans = calPower(n)-2;
        if(ans < 0)
            return ans + MOD;
        else 
            return ans;
          
    }
};