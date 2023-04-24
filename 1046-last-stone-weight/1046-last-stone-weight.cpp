class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n= stones.size();
        priority_queue<int> q;
        for(int i=0;i<n;i++)
        {
            q.push(stones[i]);
        }
        
        while(q.size() > 1)
        {
            int w1 = q.top();
            q.pop();
            int w2 = q.top();
            q.pop();
            
            if(w1!=w2)
            {
                q.push(abs(w1-w2));
            }
        }
        
        if(q.size() == 1)
            return q.top();
        else
            return 0;
    }
};