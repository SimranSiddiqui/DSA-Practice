class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        priority_queue<pair<int, char>> pq;
        
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        
        for(auto it: mp)
            pq.push(make_pair(it.second, it.first));
        
        if(pq.top().first > n/2 +n%2)
            return "";
        
        int i =0, j=1;
        while(!pq.empty())
        {
            pair<int, char> p = pq.top();
            pq.pop();
            char c = p.second;
            int count = p.first;
            
            while(i < n && count)
            {
               s[i] = c;
               i += 2;
               count--;
            }
            while(i>=n && j<n && count)
            {
               s[j] = c;
               j += 2;
               count--;
            }
        }
       
        return s;
    }
};