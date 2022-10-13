class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            if((st.empty() || st.top()<0) && asteroids[i] < 0)
            {
                st.push(asteroids[i]);
            }
            else if((st.empty() || st.top()>0 || st.top()<0) && asteroids[i] > 0)
            {
                st.push(asteroids[i]);
            }
            else if(asteroids[i]<0 && st.top()>0 )
            {
                if(abs(asteroids[i]) > abs(st.top()))
                {
                    st.pop();
                    i--;
                }
                else if(abs(asteroids[i]) == abs(st.top()))
                {
                    st.pop();
                }
            }
        }
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};