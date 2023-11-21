#define mod 1000000007

class Solution {
public:
    int rev(int n)
    {
        int num = 0;
        while(n)
        {
            int digi = n%10;
            n /= 10;
            
            num = num*10 + digi;
        }
        
        return num;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans =0;
        
        for(int i=0;i<n;i++)
        {
            int cal = nums[i] - rev(nums[i]);
            
            if(mp.find(cal) != mp.end())
            {
                ans = (ans%mod + mp[cal]%mod)%mod;
            }
            
            mp[cal]++;
        }
        
        return ans;
    }
};