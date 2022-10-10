class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,int> mp;
         mp['('] = -1;
         mp[')'] = 1;
         mp['{'] = -2;
         mp['}'] = 2;
         mp['['] = -3;
         mp[']'] = 3;
        
        stack<int> stk;
        
        for(int i=0;i<s.length();i++)
        {
            if(stk.empty())
            {
                stk.push(mp[s[i]]);
            }
            else
            {
                if(mp[s[i]] + stk.top() == 0 && stk.top()<mp[s[i]])
                {
                    stk.pop();
                }
                else 
                    stk.push(mp[s[i]]);
            }
        }
        
        if(stk.empty())
            return true;
        else 
            return false;
        
    }
};