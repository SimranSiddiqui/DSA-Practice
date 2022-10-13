class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        int m = nums1.size();
        
        for(int i=0;i<n;i++)
        {
            nums1.push_back(nums2[i]);
        }
        
        sort(nums1.begin(), nums1.end());
        
        if((m+n)%2 != 0)
            return double(nums1[(n+m)/2]);
        else 
        {
            float elem1 = nums1[(n+m)/2];
            float elem2 = nums1[(n+m)/2 - 1];
            return double (elem1+elem2)/2;
        }
            
    }
};