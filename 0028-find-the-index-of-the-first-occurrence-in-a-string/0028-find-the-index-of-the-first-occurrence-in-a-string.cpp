class Solution {
public:
    int strStr(string haystack, string needle) {
        int k = needle.length();
        int n = haystack.size();
        int ans = -1;

        if(k > n)
        return -1;

        for(int i=0;i<n;i++)
        {
            int x =0;
            for(int j =i;j<n && j<i+k;j++,x++)
            {
                if(needle[x] != haystack[j])
                {
                    ans = -1;
                    break;
                }
                else
                {
                    ans = i;
                }
            }

            if(ans != -1 && x >= k)
            break;
            else
            ans = -1;
        }

        return ans;
    }
};