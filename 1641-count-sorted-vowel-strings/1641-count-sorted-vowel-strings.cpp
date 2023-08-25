class Solution {
public:
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int solve(int n, char curr, vector<vector<int>> &dp)
    {
        if(n==0)
            return 1;
        
        int ans = 0;
        for(int i=0;i<5;i++)
        {
            if(dp[n][i] != -1)
                ans += dp[n][i];
            else if(vowels[i] >= curr)
            {  
              ans += solve(n-1, vowels[i], dp);   
            }  
        }
        
        return ans;
    }
    
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(6, -1));
        return solve(n, 'a', dp);
    }
};