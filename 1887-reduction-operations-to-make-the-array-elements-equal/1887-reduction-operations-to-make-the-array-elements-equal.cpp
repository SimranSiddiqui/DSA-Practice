class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans =0;
        int count = 0;
        
        for(int i=0;i<n;count++)
        {
            int num = nums[i];
            int freq = 0;
            while(i<n && nums[i] == num)
            {
                i++;
                freq++;
            }
            
            ans += freq*count;
        }
        
        return ans;
    }
};