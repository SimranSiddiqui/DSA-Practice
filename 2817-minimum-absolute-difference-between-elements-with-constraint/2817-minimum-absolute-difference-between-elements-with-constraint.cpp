class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        map<long long, int> st;
        st[INT_MAX]++;
        st[INT_MIN]++;
        long long ans = INT_MAX;
        
        for(int i=n-1;i>=x;i--)
        {
            st[nums[i]]++;
        }
        
        for(int i=0,j=x;i<n-1;i++)
        {   
            if(x<n && j-i < x)
            {
                st[nums[x]]--;
                if(!st[nums[x]])
                    st.erase(nums[x]);
                x++;
            }
            
            auto it = st.lower_bound(nums[i]);
            long long val1 = it->first;
            it--;
            long long val2 = it->first;
            
            ans = min(ans, abs(nums[i] - val1));
            ans = min(ans, abs(nums[i] - val2));
             
        }
        
        if(ans == INT_MIN || ans == INT_MAX)
            return 0;
        return ans;
    }
};