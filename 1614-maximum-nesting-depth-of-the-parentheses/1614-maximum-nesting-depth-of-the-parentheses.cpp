class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int ans = INT_MIN;
        int curr = 0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i] == '(')
                curr++;
            else if(s[i] == ')')
                curr--;
            
            ans = max(ans, curr);
        }
        
        return ans;
    }
};