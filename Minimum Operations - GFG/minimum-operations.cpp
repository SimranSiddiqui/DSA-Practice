//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  long func(int n, int curr, vector<int>& dp)
  {
    if(curr > n)
    return INT_MAX;
    if(curr == n)
    return 1;
    
    if(dp[curr] != -1)
    return dp[curr];
    return dp[curr] =  min(1+func(n, curr+1,dp) , 1+ func(n, curr*2, dp));
  }
    
  public:
    int minOperation(int n)
    {
        vector<int> dp(n+1, -1);
        dp[0] = 0;
       return func(n, 1, dp);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends