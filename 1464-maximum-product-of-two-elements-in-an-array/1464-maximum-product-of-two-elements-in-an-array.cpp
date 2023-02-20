class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq;
        
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
        }
        
        int n1= pq.top();
        pq.pop();
        int n2 = pq.top();
        pq.pop();
        
        return (n1-1)*(n2-1);
    }
};