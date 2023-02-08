class Solution {
public:
    int maximumSwap(int num) {
        int ans = num;
        vector<int> nums;
        while(num)
        {
            int digi = num%10;
            num /= 10;
            nums.push_back(digi);
        }
        
        int n = nums.size();
        reverse(nums.begin(), nums.end());
        
        int i=1;
        while(i<n && nums[i] <= nums[i-1])
        {
          i++;   
        }
        
        if(i>=n)
            return ans;
        
        int x = i-1;
        while(x > 0 && nums[x] == nums[x-1])
        {
            x--;
        }
        
        i = x+1;
        
        unordered_map<int, int> mp;
        int maxi = INT_MIN;
        int index = -1;
        
        for(int j=n-1;j>=i;j--)
        {
            if(mp.find(nums[j]) == mp.end() && nums[j] > nums[i-1] && nums[j] > maxi)
            {
                maxi = nums[j];
                index = j;
                mp[nums[j]]++;
            }
        }
        
       for(int j=0;j<i;j++)
       {
           if(nums[j] < maxi)
           {
               int temp = nums[j];
               nums[j] = nums[index];
               nums[index] = temp;
               break;
           }
       }
        
        ans =0;
        for(int i=0;i<n;i++)
        {
            ans = ans*10 + nums[i];
        }
        
        return ans;
    }
};