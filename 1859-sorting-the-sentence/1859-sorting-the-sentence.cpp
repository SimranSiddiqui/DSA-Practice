class Solution {
public:
    string sortSentence(string s) {
        int n = s.length();
        map<int , string> mp;
        
        for(int i=0;i<n;i++)
        {
            string x = "";
            while(!isdigit(s[i]))
            {
                x += s[i];
                i++;
            }
            
            mp[s[i] - '0'] = x;
            i++;
        }
        
        string ans = "";
        for(auto it: mp)
        {
           ans += it.second;
           ans += ' ';
        }
        
         n = ans.length();
        return ans.substr(0, n-1);
    }
};