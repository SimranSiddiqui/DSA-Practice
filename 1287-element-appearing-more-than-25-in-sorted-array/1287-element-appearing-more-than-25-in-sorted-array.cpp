class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n= arr.size();
        int totalCount =0;
        int ans;
        
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
            totalCount++;
        }
        
        for(auto it: mp)
        {
            if(it.second > totalCount/4)
            {
               ans = it.first;
                break;
            }
        }
        return ans;
    }
};