class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        
        int j =0, i=0;
        int ans = INT_MIN;
        while(j < n)
        {
            if(mp.size() == j-i)
            {
                ans = max(j-i, ans);
                cout << ans << " ";
                mp[s[j]]++;
                j++;
            }
            else
            {
                while(mp.size() < j-i)
                {
                    mp[s[i]]--;
                    
                    if(mp[s[i]] == 0)
                        mp.erase(s[i]);
                    
                    i++;
                }
            }
        }
        
        if(mp.size() == j-i)
            ans = max(ans, j-i);
        return ans;
    }
};