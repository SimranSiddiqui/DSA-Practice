class Solution {
    
    char shift(char c, long long x)
    {
        char netShift = (c-'a'+ x )%26 + 'a';
        return netShift;
    }
    
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        
        vector<long long> longShift(n);
        long long sum =0;
        for(int i=n-1;i>=0;i--)
        {
            sum += shifts[i];
            longShift[i] = sum;
        }
        
        for(int i=0;i<n;i++)
        {
           s[i] = shift(s[i], longShift[i]);  
        }
        
        return s;
    }
};