class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        int i =0,j=0;
        while(i<n && nums[i] < 0)
            i++;
        
        if(i<n && nums[i] == 0)
        {
            j =i+1;
            i = i-1;
            ans.push_back(0);
        }
        else
        {
            j = i;
            i = i-1;
        }
        
        while(i>=0 || j<n)
        {
            if(i<0 && j<n)
            {
                ans.push_back(nums[j]*nums[j]);
                j++;
            }
            else if(j>=n && i>=0)
            {
                ans.push_back(nums[i]*nums[i]);
                i--;
            }
            else if(abs(nums[i]) < abs(nums[j]))
            {
                ans.push_back(nums[i]*nums[i]);
                i--;
            }
            else
            {
                 ans.push_back(nums[j]*nums[j]);
                j++;
            }
        }
        
        return ans;
    }
};