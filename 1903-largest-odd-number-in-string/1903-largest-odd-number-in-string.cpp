class Solution {
public:
    string largestOddNumber(string num) {
        int n= num.length();
        int i;
        
        for(i=n-1;i>=0;i--)
        {
            if( (num[i]-48 )%2 !=0 )
            {
                break;
            }
            else
            {
                num.erase(num.begin()+i);
            }
        }
        
       return num;
    }
};