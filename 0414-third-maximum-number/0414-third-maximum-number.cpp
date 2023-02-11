class Solution {
public:
    int thirdMax(vector<int>& nums) {
        map<int, int, greater<int>> mp;
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        if(mp.size() < 3)
            return mp.begin()->first;
        
        int curr;
        auto it = mp.begin();
       for(int i=0; i<3; i++, it++)
       {
           curr = it->first;
       }
        
        return curr;
    }
};