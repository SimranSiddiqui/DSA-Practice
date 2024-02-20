class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int arraySum = 0;
        for(int i=0;i<n;i++)
        {
           arraySum+= nums[i]; 
        }
        return n*(n+1)/2 - arraySum;
    }
};