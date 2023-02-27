class Solution {
    
    void func(int start, int end, vector<string>& ans, string s)
    {
        if(start == 0 && end == 0  ) 
        {
            if(s[s.length() - 1] == ')')
                ans.push_back(s);
            return;
        }
        
        if(start > 0)
        {
            s += '(';
            func(start-1, end, ans, s);
            s.pop_back();
        }
        if(end > 0 && start != end)
        {
            s += ')';
            func(start, end-1, ans, s);
            s.pop_back();
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "(";
        
        func(n-1, n, ans, s);
        
        return ans;
    }
};