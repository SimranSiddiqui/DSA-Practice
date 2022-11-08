class Solution {
public:
    string makeGood(string s) {
        int n = s.length();
        stack<char> stk;
        string ans;
        int i =n-1;
        
        while(i>=0)
        {
            if(stk.empty())
            {
                stk.push(s[i]);
                i--;
            }
            else if(abs(stk.top()-s[i]) == 32)
            {
                stk.pop();
                i--;
            }
            else
            {
                stk.push(s[i]);
                i--;
            }
        }
        
       while(!stk.empty())
       {
           ans += stk.top();
           stk.pop();
       }
        
        return ans;
    }
};