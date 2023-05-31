class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = INT_MIN;
        
        int curr =0;
        unordered_map<char, int> mp;
        for(int i=0, j=0;i<n;i++)
        {
            if(mp.find(s[i]) == mp.end())
            {
                curr++;
                mp[s[i]]++;
                ans = max(ans, curr);
            }
            else
            {
                while(s[i] != s[j])
                {
                    mp.erase(s[j]);
                    curr--;
                    j++;
                }
                j++;
            }
        }
        
        if(ans == INT_MIN)
            return 0;
        return ans;
    }
};