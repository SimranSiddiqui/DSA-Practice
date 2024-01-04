class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        for(int i=0;i<n;i++)
        {
           mp[nums[i]]++;
        }
        
        int ans = 0;
        for(auto it: mp)
        {
            int freq = it.second;
            if(freq == 1)
                return -1;
            
            if(freq%3 == 0)
                ans += freq/3;
            else
                ans += freq/3 + 1;
        }
        return ans;
    }
};