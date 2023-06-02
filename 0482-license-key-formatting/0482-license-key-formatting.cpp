class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = s.length();
        string ans = "";
        
        for(int i=n-1;i>=0;)
        {
            int x = k;
            string curr = "";
            while(i>=0 && x)
            {
                if(s[i] != '-')
                {
                   curr += toupper(s[i]);
                    x--;
                }
                i--;
            }
            
           // reverse(curr.begin(), curr.end());
            
            ans += curr;
            ans += "-";
        }
        
        int i = ans.length()-1;
        while(i>=0 && ans[i] == '-')
        {
            i--;
            ans.pop_back();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};