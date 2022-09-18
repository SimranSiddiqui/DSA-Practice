class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n1 = name.length();
        int n2 = typed.length();
        
        int count1 =0;
        int count2 =0;
        
        bool ans = true;
        int i,j;
        
        for(i=0,j=0;i<n1 && j<n2;)
        {
            count1 =0;
            count2 =0;
            
            if(name[i]!=typed[j])
            {
                ans = false;
                break;
            }
            char c1 = name[i];
            char c2 = typed[j];
            
            while(name[i]==c1)
            {
                i++;
                count1++;
            }
            
            while(typed[j]==c2)
            {
                j++;
                count2++;
            }
            
            if(count1>count2)
            {
                ans = false;
                break;
            }
            
        }
        
         if(i<n1 || j<n2 )
             return false;
        
            return ans;
        
    }
};