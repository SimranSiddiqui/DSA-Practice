class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums1[i][0]] = nums1[i][1];
        }
        
        vector<vector<int>> ans;
        for(int i=0;i<m;i++)
        {
            if(mp.find(nums2[i][0]) == mp.end())
            {
                ans.push_back(nums2[i]);
            }
            else
            {
                vector<int> x;
                x.push_back(nums2[i][0]);
                x.push_back(nums2[i][1] + mp[nums2[i][0]]);
                ans.push_back(x);
                mp.erase(nums2[i][0]);
            }
        }
        
        for(auto it: mp)
        {
            vector<int> x;
            x.push_back(it.first);
            x.push_back(it.second);
            ans.push_back(x);
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};