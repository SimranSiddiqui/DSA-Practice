class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        
        
        int v1=0,v2=0;
        for(int i=0,j=n-1;i<j;i++,j--)
        {
            if(isVowel(s[i]))
                v1++;
            if(isVowel(s[j]))
                v2++;
        }
        
        if(v1==v2)
            return true;
        return false;
    }
    
    bool isVowel(char c)
    {
        c = tolower(c);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            return true;
        else
        return false;
    }
    
    
};