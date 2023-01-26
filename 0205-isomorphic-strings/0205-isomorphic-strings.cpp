class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        unordered_map<char, char> mp;
        unordered_map<char, char> rev;
        
        if(m != n)
            return false;
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i]) == mp.end() && rev.find(t[i]) == rev.end())
            {
               mp[s[i]] = t[i];  
               rev[t[i]] = s[i];
            }
            else if(mp[s[i]] != t[i] || rev[t[i]] != s[i])
                return false;
        }
        
        return true;
        
    }
};