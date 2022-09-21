class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            int index = abs(nums[i])-1;
            if(nums[index]>0)
                nums[index] = -1*nums[index];
            else
                ans.push_back(abs(nums[i]));
                
        }
        
        return ans;
    }
};