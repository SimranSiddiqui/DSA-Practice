class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long n = hours.size();
        unordered_map<long long, long long> mp;
        long long ans = 0;
        
        for(int i=0;i<n;i++)
        {
            if(hours[i]%24 == 0 && mp.find(0) != mp.end())
                ans += mp[0];
            else if(mp.find(24 - hours[i]%24) != mp.end())
                ans += mp[24 - hours[i]%24];
            
            mp[hours[i]%24]++;
        }
        
        return ans;
    }
};