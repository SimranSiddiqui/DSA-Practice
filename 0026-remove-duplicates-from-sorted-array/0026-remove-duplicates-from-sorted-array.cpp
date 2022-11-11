class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int uniquePtr=0, allPtr=1;
        while(allPtr<nums.size())
        {
            if(nums[allPtr] == nums[allPtr-1])
                allPtr++;
            else 
            {
                uniquePtr++;
                nums[uniquePtr] = nums[allPtr];
                allPtr++;
            }
        }
        
        return uniquePtr+1;
    }
};