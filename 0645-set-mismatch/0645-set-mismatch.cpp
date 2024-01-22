class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int miss, rep;
        
        if(nums[0] == 1)
            miss = n;
        else
            miss = 1;
        
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(i<n-1 && nums[i+1]-nums[i] == 0)
            { 
                rep = nums[i];
            }
            else if(i<n-1 && nums[i+1]-nums[i] != 1)
            {
                miss = nums[i] +1;
            }
        }
        
        ans.push_back(rep);
        ans.push_back(miss);
        
        return ans;
    }
};