class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int, int> mp;
        set<pair<int, int>> st;
        int ans =INT_MIN, init = 0;
        int i=0, j=0;
        
        for(;j<n;)
        {
            if(!st.empty())
                init = st.rbegin()->first;
            
            if(st.empty() || st.rbegin()->first <= k){
                ans = max(j-i, ans);
                if(mp.find(nums[j]) != mp.end())
                st.erase({mp[nums[j]], nums[j]});
                
                mp[nums[j]]++;
                
                st.insert({mp[nums[j]], nums[j]});
                
                j++;
            }
            else
            {
                while(st.rbegin()->first > k){
                    st.erase({mp[nums[i]], nums[i]});
                    mp[nums[i]]--;
                    st.insert({mp[nums[i]], nums[i]});
                    i++;
                }
            }
        }
        
        while(st.rbegin()->first > k){
                    st.erase({mp[nums[i]], nums[i]});
                    mp[nums[i]]--;
                    st.insert({mp[nums[i]], nums[i]});
                    i++;
                }
        ans = max(j-i, ans);
        
        return ans;
    }
};