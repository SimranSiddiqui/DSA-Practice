class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int n = s.length();
        unordered_map<char, int> mp;
        
        for(int i=0;i<n;i++){
            mp[s[i]] = i;
        }
        
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans += abs(i - mp[t[i]]);
        }
        
        return ans;
    }
};