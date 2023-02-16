//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
    
    void func(vector<int>& arr, int n, vector<int>& ans, int sum, int i)
    {
        if(i >= n)
        {
            ans.push_back(sum);
            return;
        }
        
        sum += arr[i];
        func(arr, n, ans, sum, i+1);
        sum -= arr[i];
        func(arr, n, ans, sum, i+1);
    }
    
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        int sum =0;
        
        func(arr, N, ans, sum, 0);
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends