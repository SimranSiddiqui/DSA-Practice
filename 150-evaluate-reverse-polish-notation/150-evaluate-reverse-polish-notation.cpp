class Solution {
public:
    #define ll long long
    
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<long long> s;
        
        for(int i=0;i<n;i++)
        {
            if(tokens[i] == "+")
            {
                ll x1 = s.top();
                s.pop();
                ll x2 = s.top();
                s.pop();
                long long x = x1+x2;
                s.push(x);
            }
            else if(tokens[i] == "-")
            {
                ll x1 = s.top();
                s.pop();
                ll x2 = s.top();
                s.pop();
                long long x = x2-x1;
                s.push(x);
            }
            else if(tokens[i] == "*")
            {
                ll x1 = s.top();
                s.pop();
                ll x2 = s.top();
                s.pop();
                long long x = x1*x2;
                s.push(x);
            }
            else if(tokens[i] == "/")
            {
                ll x1 = s.top();
                s.pop();
                ll x2 = s.top();
                s.pop();
                long long x = x2/x1;
                s.push(x);
            }
            else
            {
                long long x = stoi(tokens[i]);
                s.push(x);
            }
        }
        
        return s.top();
    }
};