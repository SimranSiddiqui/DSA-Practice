class Solution {
public:
    string finalString(string s) {
        int n = s.length();
        string x = "";
        int count =0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i] == 'i')
            {
                reverse(x.begin(), x.begin()+i-count);
                count++;
            }
            else
                x += s[i];
        }
        
        return x;
    }
};