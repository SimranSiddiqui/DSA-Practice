//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int n = s.length();
        int ans = INT_MIN;
        unordered_map<char, int> mp;
        
        int j = 0, i=0;
        while(j < n)
        {
            if(mp.size() < k)
            {
                mp[s[j]]++;
                j++;
            }
            else if(mp.size() > k)
            {
                while(mp.size() > k)
                {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                    mp.erase(s[i]);
                
                    i++;
                }
            }
            else 
            {
                ans = max(ans, j-i);
                mp[s[j]]++;
                j++;
            }
        }
        
        if(mp.size() == k)
        ans = max(ans, j-i);
        if(ans == INT_MIN)
        ans = -1;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends