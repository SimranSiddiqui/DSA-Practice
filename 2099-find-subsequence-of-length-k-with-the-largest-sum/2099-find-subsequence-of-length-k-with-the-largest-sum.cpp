class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        for(int i=0;i<n;i++)
        {
            pq.push(make_pair(nums[i], i));
        }
        
        vector<int> ans;
        
        vector<pair<int,int>> vec;
        while(k--)
        {
            pair<int, int> x = pq.top();
            pq.pop();
            vec.push_back(x);
        }
        
        sort(vec.begin(), vec.end(), [&](auto &a, auto &b)
             {
                 return a.second < b.second ; 
             });
        
        for(auto it: vec)
        {
            ans.push_back(it.first);
        }
        
        return ans;
    }
};