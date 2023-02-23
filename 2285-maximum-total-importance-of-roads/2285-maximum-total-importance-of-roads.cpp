class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        
        
        int s = roads.size();
        unordered_map<long long, long long> mp;
        for(int i=0;i<s;i++)
        {
            mp[roads[i][0]]++;
            mp[roads[i][1]]++;
        }
        
        priority_queue<pair<long long, long long>> pq;
        for(auto it : mp)
        {
            pq.push(make_pair(it.second, it.first));
        }
        
        mp.clear();
        while(!pq.empty() && n > 0)
        {
            pair<int, int> x = pq.top();
            mp[x.second] = n--;
            pq.pop();
        }
        
        long long ans =0;
        for(int i=0;i<s;i++)
        {
            ans += mp[roads[i][0]] + mp[roads[i][1]];
        }
        
        return ans;
    }
};