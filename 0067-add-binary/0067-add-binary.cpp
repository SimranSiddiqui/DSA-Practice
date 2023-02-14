class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int sum =0;
        string ans = "";

        int n = a.length(), m = b.length();

        for(int i=n-1,j=m-1; i>=0 || j>=0; i--, j--)
        {
            int x1, x2, sum =0;
             if(i<0)
             {
                x1 =0;
                x2 = b[j]-'0';
             }
             else if(j<0)
             {
                 x2 = 0;
                 x1 = a[i]-'0';
             }
             else
             {
                 x1 = a[i]-'0';
                 x2 = b[j]-'0';
             }

             sum = x1+x2+carry;
             if(sum == 2)
             {
                 ans += to_string(0);
                 carry = 1;
             }
             else if(sum == 3)
             {
                 ans += to_string(1);
                 carry = 1;
             }
             else if(sum == 0)
             {
                 ans += to_string(0);
                 carry = 0;
             }
             else
             {
                 ans += to_string(1);
                 carry =0;
             }

        }

        if(carry)
        ans += to_string(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};