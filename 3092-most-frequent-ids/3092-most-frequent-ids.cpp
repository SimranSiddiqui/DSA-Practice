class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        
        unordered_map<int, long long> mp1;
        map<pair<long long, int>, int> mp2;
        vector<long long> ans;
        
        long long init = 0;
        for(int i=0;i<n;i++)
        {
            if(mp1.find(nums[i]) != mp1.end()){
            init = mp1[nums[i]];
            mp2.erase({init, nums[i]});
            }
            
            mp1[nums[i]] += freq[i];
            mp2[{mp1[nums[i]], nums[i]}] = nums[i];
            
            long long maxi = (mp2.rbegin()->first).first;
            ans.push_back(maxi);
        }
        
        return ans;
    }
};