class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int count = 0;
        priority_queue<int> pq;
        
        if(a)
            pq.push(a);
        if(b)
            pq.push(b);
        if(c)
            pq.push(c);
        
        while(pq.size() >= 2)
        {
            int x1 = pq.top();
            pq.pop();
            int x2 = pq.top();
            pq.pop();
            
            x1--;
            x2--;
            count++;
            
            if(x1)
                pq.push(x1);
            if(x2)
                pq.push(x2);
        }
        
        return count;
    }
};