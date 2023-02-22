class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue< pair<int, int> > pq;
        
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto it : mp)
        {
            pq.push(make_pair(it.second, it.first));
        }
        
        vector<int> ans;
        while(k-- && !pq.empty())
        {
            pair<int, int> x = pq.top();
            pq.pop();
            ans.push_back(x.second);
        }
        
        return ans;
    }
};