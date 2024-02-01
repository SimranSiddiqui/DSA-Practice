class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            vector<int> x;
            x.push_back(nums[i]);
            while(x.size() < 3)
            {
                i++;
                if(nums[i] - nums[i-1] > k)
                    return {};
                else
                    x.push_back(nums[i]);
            }
            
            if(x[2] - x[0] > k)
                return {};
            ans.push_back(x);
        }
        
        return ans;
    }
};