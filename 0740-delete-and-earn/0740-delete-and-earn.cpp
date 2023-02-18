class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
       sort(nums.begin(),nums.end());
       int n = nums.size();
       int m = nums[n-1];
       vector<int>v(m+1,0),dp(m+1,0);
       for(int i = 0;i < n; i++){
           v[nums[i]]+=nums[i];
       }
   
       dp[0]=0;
       dp[1] = v[1];
       for(int i = 2; i < m+1; i++){
           dp[i] = max(dp[i-1],v[i] + dp[i-2]);
       }
       return dp[m];
    }
};