class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2 ==0)
            mp[nums[i]]++;
        }
        
        int minElem = INT_MAX;
        int maxFreq = INT_MIN;
        
        if(mp.empty())
            return -1;
        
        for(auto it : mp)
        {
            maxFreq = max(maxFreq, it.second);
        }
        
        for(auto it : mp)
        {
            if(it.second == maxFreq)
            {
                if(it.first < minElem)
                    minElem = it.first;
            }
        }
        
        return minElem;
    }
};