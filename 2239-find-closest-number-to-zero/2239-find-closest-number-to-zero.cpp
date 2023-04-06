class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int neg = INT_MAX, pos = INT_MAX;
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 0)
                return 0;
            else if(nums[i] > 0)
                pos = min(pos, nums[i]);
            else
                neg = min(neg, nums[i]*-1);
        }
        
        if(neg == pos)
            return pos;
        else if(neg < pos)
            return neg*-1;
        return pos;
    }
};