class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n+1,-1);
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            arr[nums[i]] = 1;
        }
        
        int j;
        for(int i=1,j=0;i<n+1;i++)
        {
            if(arr[i] == -1)
            {
                ans.push_back(i);
            }
        }
        
        return ans;
       
    }
};