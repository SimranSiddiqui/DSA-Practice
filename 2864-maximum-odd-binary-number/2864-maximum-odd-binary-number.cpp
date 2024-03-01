class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = count(s.begin(), s.end(), '1');
        int n = s.length();
        
        s[n-1] = '1';
        for(int i=0;i<n-1;i++)
        {
            if(i < ones-1)
                s[i] = '1';
            else
               s[i] = '0'; 
        }
        
        return s;
    }
};