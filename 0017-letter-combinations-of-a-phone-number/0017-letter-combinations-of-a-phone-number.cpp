class Solution {
    void helper(string digits, int n, unordered_map<int, vector<char>> &mp, string &x, int i, vector<string> &ans)
    {
        if(i == n)
        {
            if(x.size()>0)
            ans.push_back(x);
            return ;
        }
        
        int num = digits[i] - '0';
        
       string x1 = x + mp[num][0];
       string x2 = x + mp[num][1];
       string x3 = x + mp[num][2];
       string x4 = x;
        
       if(num == 7 || num == 9)
           x4 += mp[num][3];
        
        helper(digits, n, mp, x1, i+1, ans);
        helper(digits, n, mp, x2, i+1, ans);
        helper(digits, n, mp, x3, i+1, ans);
        
        if(num == 7 || num == 9)
        helper(digits, n, mp, x4, i+1, ans);
        
    }
    
    
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        unordered_map<int, vector<char>> mp;
        char x = 'a';
        int j =0;
        for(int i=2;i<=9;i++)
        {
            if(i!=7 && i!=9)
              j = 3;
            else
               j=4;
            
            while(j--)
            {
               mp[i].push_back(x);
                x++;
            }
        }
        
        vector<string> ans;
        string temp = "";
        
        helper(digits, n, mp, temp, 0, ans);
        
        return ans;
        
        
    }
};