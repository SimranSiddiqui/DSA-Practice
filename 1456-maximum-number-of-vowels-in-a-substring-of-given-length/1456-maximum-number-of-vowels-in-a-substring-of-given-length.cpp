class Solution {

bool isVowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' )
    return true;
    else
    return false;
}

public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int count =0, ans = INT_MIN;

        for(int i=0,j=0;j<n;)
        {
            if(j-i < k)
            {
                if(isVowel(tolower(s[j])))
                {
                    count++;
                }
                j++;
            }
            else
            {
               ans = max(ans, count);

               if(isVowel(s[i]))
               {
                   count--;
               }
               if(isVowel(s[j]))
               {
                   count++;
               }

               i++;
               j++;
            }   
        }

        ans = max(ans, count);

        return ans;
    }
};