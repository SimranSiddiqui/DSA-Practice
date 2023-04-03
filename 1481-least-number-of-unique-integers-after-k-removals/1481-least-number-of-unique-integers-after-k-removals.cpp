class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        
        priority_queue< pair<int, int>, vector<pair<int, int>> ,greater<pair<int, int>> > pq;
        
        for(auto it: mp)
        {
            pq.push(make_pair(it.second, it.first));
        }
        
        while(k)
        {
            pair<int, int> x = pq.top();
            int freq = x.first;
            
            if(freq <= k)
            {
                pq.pop();
                k -= freq;
            }
            else
            {
                k = 0;
            }
        }
        
        return pq.size();
    }
};