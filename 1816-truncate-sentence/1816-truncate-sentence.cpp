class Solution {
public:
    string truncateSentence(string s, int k) {
        int i=0;
        while(k && i<s.length())
        {
            if(i<s.length() && s[i] == ' ')
            {
                k--;
            }
            i++;
        }
        
        if(k==0)
        return s.substr(0,i-1);
        else
            return s;
    }
};