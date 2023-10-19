class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        
        int n1 = s.length();
        int n2 = t.length();
        
        for(int i=0;i<n1;i++)
        {
            if(s[i] == '#' && st1.empty())
                continue;
            else if(s[i] == '#')
                st1.pop();
            else
                st1.push(s[i]); 
        }
        
        for(int i=0;i<n2;i++)
        {
            if(t[i] == '#' && st2.empty())
                continue;
            else if(t[i] == '#')
                st2.pop();
            else
                st2.push(t[i]); 
        }
        
        if(st1.size() != st2.size())
            return false;
        else
        {
            while(!st1.empty())
            {
                if(st1.top() == st2.top())
                {
                    st1.pop();
                    st2.pop();
                }
                else
                    break;
            }
        }
        
        if(!st1.empty() || !st2.empty())
            return false;
        return true;
        
    }
};