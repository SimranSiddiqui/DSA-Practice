//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    int solve(int n, int x, int y, int z, vector<int> &dp)
    {
        if(n == 0)
        return 0;
        if(n < 0)
        return INT_MIN;
        
        if(dp[n] != -1)
        return dp[n];
        
        return dp[n] = 1+ max(solve(n-x, x, y, z, dp) , max(solve(n-y, x, y, z, dp) , solve(n-z, x, y, z, dp) ));
    }
    public:
   
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1, -1);
        int ans = solve(n, x, y, z, dp);
        
        if(ans > 0)
        return ans;
        else
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends