class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        
        int check = 0;
        for(int i=1;i<n;i++)
        {
            if(s[i-1] != s[i])
                check++;
        }
        
        if(check > 1)
            return false;
        else
            return true;
        
    }
};