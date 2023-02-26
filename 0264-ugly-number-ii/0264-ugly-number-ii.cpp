class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_map<long long, bool> mp;
        
        pq.push(1);
        mp[1] = true;
        
        while(!pq.empty() && n)
        {
            long long x = pq.top();
            pq.pop();
            n--;
            
            if(n == 0)
                return x;
            
            if(mp.find(x*2) == mp.end())
            {
                mp[x*2] = true;
                pq.push(x*2);
            }
            if(mp.find(x*3) == mp.end())
            {
                mp[x*3] = true;
                pq.push(x*3);
            }
            if(mp.find(x*5) == mp.end())
            {
                mp[x*5] = true;
                pq.push(x*5);
            }
        }
        
        return -1;
    }
};