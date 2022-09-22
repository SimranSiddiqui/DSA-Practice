class Solution {
public:
    string reverseWords(string s) {
        int i =0;
        int j =0;
        int n = s.length();
        
        while(i<n && j<n)
        {
            while(s[j] != ' ' && j<n)
            {
                j++;
            }
            
            int a = i, b=j-1;
            
            while(a<b)
            {
                char temp = s[a];
                s[a] = s[b];
                s[b] = temp;
                
                a++;
                b--;
            }
            
            j++;
            i=j;
        }
        
        return s;
    }
};