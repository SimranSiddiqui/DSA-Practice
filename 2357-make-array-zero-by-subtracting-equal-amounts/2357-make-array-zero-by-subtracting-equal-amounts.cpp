class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        for(int i=0;i<n;i++)
        {
            if(nums[i] != 0)
            pq1.push(nums[i]);
        }
        
        int count =0;
        while(!pq1.empty() || !pq2.empty())
        {
            if(pq1.empty())
            {
                int diff =0;
                if(!pq2.empty())
                {
                    diff = pq2.top();
                    pq2.pop();
                }
                while(!pq2.empty())
                {
                    int x = pq2.top();
                    pq2.pop();
                    x -= diff;
                    if(x > 0)
                    pq1.push(x);
                }
                
                count++;
            }
            else if(pq2.empty())
            {
                int diff =0;
                if(!pq1.empty())
                {
                    diff = pq1.top();
                    pq1.pop();
                }
                while(!pq1.empty())
                {
                    int x = pq1.top();
                    pq1.pop();
                    x -= diff;
                    if(x > 0)
                    pq2.push(x);
                }
                
                count++;
            }
        }
        
        return count;
        
    }
};