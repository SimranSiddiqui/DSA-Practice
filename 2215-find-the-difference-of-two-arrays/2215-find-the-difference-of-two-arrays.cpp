class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        for(int i=0;i<n1;i++)
        {
            mp[nums1[i]]++;
        }
        
        int n =2;
        vector<vector<int>> ans(2);
        for(int i=0;i<n2;i++)
        {
           if(mp.find(nums2[i]) == mp.end())
           {
            ans[1].push_back(nums2[i]);
               mp[nums2[i]]++;
           }
        }
        
        for(int i=0;i<n2;i++)
        {
            if(mp.find(nums2[i]) != mp.end())
                mp.erase(nums2[i]);
        }
        
        for(auto it : mp)
        {
            ans[0].push_back(it.first);
        }
        
        return ans;
    }
};