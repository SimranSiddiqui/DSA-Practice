class Solution {
    
    bool pal(string s)
    {
        int n = s.length();
        int i =0;
        int j =n-1;
        while(i<j)
        {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int n = words.size();
        int count =0;
        int maxPal =0;
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(words[i])!=mp.end() && mp[words[i]]>0)
            {
                count += words[i].length()*2;
                mp[words[i]]--;
            }
            else
            {
                string x = words[i];
                reverse(x.begin(), x.end());
                mp[x]++; 
            }
        }
        
        int maxi = INT_MIN;
        for(auto it: mp)
        {
            if(pal(it.first) && it.second%2 != 0)
            {
                string x = it.first;
                int len = x.length();
                maxi = max(maxi, len);
            }
        }
        
        if(maxi != INT_MIN)
        count += maxi;
        return count;
    }
};