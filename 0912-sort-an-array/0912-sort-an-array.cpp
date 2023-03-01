class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
        }
        
        int i =0;
        while(!pq.empty())
        {
            nums[i++] = pq.top();
            pq.pop();
        }
        
        return nums;
    }
};