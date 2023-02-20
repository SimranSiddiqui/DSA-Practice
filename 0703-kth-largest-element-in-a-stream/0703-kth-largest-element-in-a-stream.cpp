class KthLargest {
public:
    priority_queue<int> pq;
    int kth;
    
    KthLargest(int k, vector<int>& nums) {
        int n = nums.size();
        kth = k;
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]*-1);
        }
        
        while(pq.size() > kth)
        {
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val*-1);
        while(pq.size() > kth)
        {
            pq.pop();
        }
        
        int ans = pq.top()*-1;

        return ans;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */