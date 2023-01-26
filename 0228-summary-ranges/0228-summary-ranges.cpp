class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        
        for(int i=0,j=0;j<n;j++)
        {
            i = j;
            string x = "";
            while(j+1<n && nums[j+1] == nums[j]+1)
            {
                j++;
            }
            
            if(i == j)
            {
                x += to_string(nums[j]);
            }
            else
            {
                x += to_string(nums[i]);
                x += "->";
                x += to_string(nums[j]);
            }
            
            ans.push_back(x);
        }
        
        return ans;
    }
};