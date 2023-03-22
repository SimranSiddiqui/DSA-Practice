class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
/*
        if(columnNumber <= 26)
        {
            ans  += 'A'-1 + columnNumber;
            return ans;
        }
*/
        if(columnNumber % 26 == 0 && columnNumber > 26)
        {
            ans += 'A'-1 + (columnNumber/26)-1;
            ans += 'Z';
            return ans;
        }

        while(columnNumber)
        {
            if(columnNumber <= 26)
            {
                ans += 'A'-1 + columnNumber;
                break;
            }
    
            int x = columnNumber%26;
            if(x <= 26)
            {
                 char xx = 'A'-1 + x;
                 ans += xx;
                 columnNumber /= 26;
            }
            else
            {
                ans += 'Z';
                columnNumber -= 26*26;
            }
           
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};