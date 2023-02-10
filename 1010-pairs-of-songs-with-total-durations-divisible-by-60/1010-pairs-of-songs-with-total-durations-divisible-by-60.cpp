class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int ans =0;
        unordered_map<int, int> mp;
        
        for(int i=0;i<n;i++)
        {
            int curr = time[i];
            if(curr % 60 == 0)
            {
                if(mp.find(60) != mp.end())
                {
                    ans += mp[60];
                }
                mp[60]++;
            }
            else
            {
                if(mp.find(60 - curr%60) != mp.end())
                    ans += mp[60-curr%60];
                
                mp[curr%60]++;
            }
        }
        
        return ans;
        
    }
};