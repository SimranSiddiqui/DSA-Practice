class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bits(32, 0);
        int ans = INT_MAX;
        int orVal = 0;
        int i=0,j=0;
        
        for(;j<n;)
        {
            if(nums[j] >= k)
                return 1;
            if(orVal < k){
                orVal |= nums[j];
                
                for(int x=0;x<32;x++)
                {
                    if((1 << x) & nums[j])
                        bits[x]++;
                }
                
                j++;
            }
            else
            {
                while(i<j && orVal >= k){
                    cout << "yes";
                    ans = min(ans, j-i);
                    for(int x=0;x<32;x++)
                    {
                       if((1 << x) & nums[i])
                       {
                           if(bits[x] == 1)
                           orVal -= (1 << x);
                           
                           bits[x]--;
                       }
                    }
                    
                    i++;
                 }
            }
        }
        
        
        while(i<n && orVal >= k){
            cout << "no" ;
                    ans = min(ans, j-i);
                    for(int x=0;x<32;x++)
                    {
                       if((1 << x) & nums[i])
                       {
                           if(bits[x] == 1)
                           orVal -= (1 << x);
                           
                           bits[x]--;
                       }
                    }
                    
                    i++;
        }
        
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};