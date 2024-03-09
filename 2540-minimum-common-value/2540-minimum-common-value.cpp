class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        int n = nums1.size();
        int m = nums2.size();
        
        for(int i=0;i<n;i++)
        {
            mp[nums1[i]]++;
        }
        
        for(int i=0;i<m;i++)
        {
            if(mp.find(nums2[i]) != mp.end()) 
                return nums2[i];
        }
        
        return -1;
       
    }
};