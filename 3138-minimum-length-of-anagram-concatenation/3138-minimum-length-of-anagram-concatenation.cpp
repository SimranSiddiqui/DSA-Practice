class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.length();
        unordered_map<int, int> mp;
        int mini = INT_MAX;
        int ans;
        
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            ans = mp[s[i]];
        }
        
        
        for(auto it: mp){
            ans = __gcd(ans, it.second);
        }
        
        return n/ans;
    }
};