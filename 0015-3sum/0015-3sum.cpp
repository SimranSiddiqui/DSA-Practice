class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n;)
        {
            int target = nums[i];
            int l = i+1, r = n-1;
            while(l<r)
            {
                vector<int> curr;
                if(target + nums[l] + nums[r] == 0)
                {
                    curr.push_back(nums[l]);
                    curr.push_back(nums[r]);
                    curr.push_back(nums[i]);
                    
                    ans.push_back(curr);
                    
                    while(l<n && nums[l] == curr[0])
                        l++;
                }
                else if(target + nums[l] + nums[r] < 0)
                    l++;
                else
                    r--;
            }
            
            while(i<n && nums[i] == target)
                i++;
        }
        
        return ans;
    }
};