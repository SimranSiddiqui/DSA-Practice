class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.length();
        int count = 0;
        int ans = INT_MIN;
        
        for(int i=1;i<n;i++)
        {
            if(num[i] == num[i-1])
            {
                count++;
            }
            else
            {
                count =0;
            }
            if(count == 2)
            {
                int x = num[i]-48;
                ans = max(ans, x);
            }   
            
        }
        
        if(ans > INT_MIN)
        {
            string x = "";
            for(int i=0;i<3;i++)
            x += ans+48;
            return x;
        }
        else
            return "";
    }
};