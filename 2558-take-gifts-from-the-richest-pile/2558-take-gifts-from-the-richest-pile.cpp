class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long n = gifts.size();
        
        for(int i=0;i<n;i++)
        {
            pq.push(gifts[i]);
        }
        
        while(k-- && pq.size())
        {
            int curr = pq.top();
            pq.pop();
            
            curr = floor(sqrt(curr));
            
            if(curr)
            pq.push(curr);
        }
        
        long long ans = 0;
        while(!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        
        return ans;
        
    }
};