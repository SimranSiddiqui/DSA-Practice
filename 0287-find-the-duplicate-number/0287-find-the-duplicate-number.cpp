class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        for(int curr=nums[0];curr < n;)
        {
            if(nums[curr] == -1)
                return curr;
            else
            {
                int temp = nums[curr];
                nums[curr] = -1;
                curr = temp;
            }
        }
        
        return -1;
    }
};