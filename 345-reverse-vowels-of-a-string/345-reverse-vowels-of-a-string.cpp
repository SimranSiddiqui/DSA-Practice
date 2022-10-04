class Solution {
    
    bool isvowel(char c)
    {
        if(c=='a' || c=='e' || c== 'i' || c=='o' || c=='u' || c=='A' || c=='E' || c== 'I' || c=='O' || c=='U')
            return true;
        else
            return false;
    }
    
public:
    string reverseVowels(string s) {
        int n = s.length();
        int i=0;
        int j=n-1;
        
        while(i<j)
        {
            while(i<n && !isvowel(s[i]))
                i++;
            while(j>=0 && !isvowel(s[j]))
                j--;
            
            if(i<j)
            {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
            }
        }
        
        return s;
    }
};