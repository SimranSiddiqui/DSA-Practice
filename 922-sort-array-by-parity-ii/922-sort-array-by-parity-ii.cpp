class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int i=0, j=1;
        
        while(i<n && j<n)
        {
            if(nums[i]%2!=0 && nums[j]%2==0)
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                
                i+=2;
                j+=2;
            }
            else if(nums[i]%2==0)
                i+=2;
            else
                j+=2;
        }
        
        return nums;
    }
};