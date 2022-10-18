class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        for( int i=2; i<=n; i++)
        {
            string lastString =ans;
            int l=ans.size();
            int j=0;
            ans="";

            while( j<l)
            {

                int ct=j;
                while( j<l and lastString[j]==lastString[ct])ct++;
                ans+=to_string(ct-j)+lastString[j];
                j=ct;
            }

        }

        return ans;
        
    }
};