class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        int i=0;
        
       if(s[0] == 'b')
       {
           while(i<n)
           {
               if(s[i] == 'a')
                   return false;
               i++;
           }
           return true;
       }
        else
        {
           while(i<n && s[i] == 'a')
               i++;
            
            while(i<n)
            {
                if(s[i] == 'a')
                    return false;
               i++;
            }
            return true;
        }
        
        return true;
    }
};