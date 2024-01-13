class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> mp;
        int n = s.length();
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(t[i]) == mp.end())
                ans++;
            else
            {
                mp[t[i]]--;
                if(mp[t[i]] == 0)
                    mp.erase(t[i]);
            }
        }
        
        return ans;
    }
};