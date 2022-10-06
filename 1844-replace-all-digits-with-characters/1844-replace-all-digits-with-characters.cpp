class Solution {
    
    char shift(char c, char x)
    {
        int xchar = x-'0';
        char newChar = c+ xchar;
        return newChar;
    }
    
public:
    string replaceDigits(string s) {
        int n = s.length();
        
        for(int i=0;i<n;i++)
        {
            if(i%2 != 0)
            {
                s[i] = shift(s[i-1],s[i]);
            }
        }
        
        return s;
    }
};