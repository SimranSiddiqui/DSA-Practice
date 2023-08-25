class Solution {
public:
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int solve(int n, char curr)
    {
        if(n==0)
            return 1;
        
        int ans = 0;
        for(int i=0;i<5;i++)
        {
            if(vowels[i] >= curr)
              ans += solve(n-1, vowels[i]);   
        }
        
        return ans;
    }
    
    int countVowelStrings(int n) {
        return solve(n, 'a');
    }
};