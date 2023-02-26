class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        priority_queue<pair<int,pair<int,int>>>pq;
        int sum=0;
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++)
            {
                if(pq.size()<k)
                {
                    pq.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
                }
                else if(pq.size()==k and nums1[i]+nums2[j]>pq.top().first)
                {
                    break;
                }
                else if(pq.size()==k and nums1[i]+nums2[j]<=pq.top().first){
                    pq.pop();
                    pq.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
                }
            }
        }

        vector<vector<int>>ans;
        while(pq.size()> k){
            pq.pop();
        }
        
        while(!pq.empty())
        {
              ans.push_back({pq.top().second.first,pq.top().second.second});
              pq.pop();
        }
        return ans;
    }
};