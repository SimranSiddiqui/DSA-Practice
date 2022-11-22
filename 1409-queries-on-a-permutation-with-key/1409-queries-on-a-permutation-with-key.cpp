class Solution {
    
    int linearSearch(int i, int j, int target, vector<int> nums)
    {
        while(i<=j)
        {
            if(nums[i] == target)
                return i;
            
            i++;
        }
        
        return -1;
    }
    
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();
        
        vector<int> nums;
        for(int i=1;i<=m;i++)
        {
            nums.push_back(i);
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int q = queries[i];
            int index = linearSearch(0, m-1, q, nums);
            
            ans.push_back(index);
            
            for(int j=index;j>0;j--)
            {
                 int temp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = temp;
            }
        }
        
        return ans;
    }
};