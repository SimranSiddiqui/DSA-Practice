class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mp;
        vector<int> ans;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }

        for(auto it : mp)
        {
            pq.push(make_pair(it.second, it.first));
        }

        while(k--)
        {
           ans.push_back(pq.top().second);
           pq.pop();
        }

        return ans;
    }
};