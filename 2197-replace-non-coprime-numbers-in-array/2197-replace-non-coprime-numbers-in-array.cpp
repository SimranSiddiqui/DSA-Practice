class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        
        for(int i=0;i<n;i++)
        {
           st.push(nums[i]);
            while(st.size()>1)
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                
                if(__gcd(a,b) > 1)
                {
                    st.push(lcm(a,b));
                }
                else
                {
                    st.push(b);
                    st.push(a);
                    break;
                }
            }
        }
        
        vector<int> ans;
        while(!st.empty())
        {
            int x = st.top();
            ans.push_back(x);
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};