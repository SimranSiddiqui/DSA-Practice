class Solution {
    
    bool check(string s)
    {
        int i =0 , j= s.length()-1;
        while(s[i] == '1')
            i++;
        while(s[j] == '0')
            j--;
        
        if(j == i-1)
            return true;
        return false;
    }
    
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.length();
        int count =0;
        if(s.length() == 1)
            return 0;
        
        
        bool flag = false;
       while( !flag)
        {
            flag = true;
             for(int i=0;i<n-1;i++)
            {
                 if(s[i] == '0' && s[i+1] == '1')
                 {
                     flag = false;
                     char temp = s[i];
                     s[i] = s[i+1];
                     s[i+1] = temp;
                     i++;
                 }
             }
            
            count++;
        }
        
        return count-1;
       
    }
};