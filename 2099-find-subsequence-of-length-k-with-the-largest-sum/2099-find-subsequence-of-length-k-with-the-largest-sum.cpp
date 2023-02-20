class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        int n = nums.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            pq.push(make_pair(nums[i], i));
        }
        
        map<int, int> mp;
        while(k--)
        {
            mp[pq.top().second] = pq.top().first;  
            pq.pop(); 
        }
        
        for(auto it : mp)
            ans.push_back(it.second);
        
        return ans;
        
    }
};