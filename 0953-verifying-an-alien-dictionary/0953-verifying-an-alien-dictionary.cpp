class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        int n = order.length();
        
        for(int i=0;i<n;i++)
        {
            mp[order[i]] = i;
        }
        
        int size = words.size();
        
        for(int k=0;k<size-1;k++)
        {
            string s1 = words[k];
            string s2 = words[k+1];
            
            int i =0, j=0;
            while(i<s1.length() && j<s2.length())
            {
                if(mp[s1[i]] > mp[s2[j]])
                    return false;
                else if(mp[s1[i]] < mp[s2[j]])
                {
                    i = s1.length();
                    j = s2.length();
                }
                
                i++;
                j++;
            }
            
            if(i<s1.length() && j>=s2.length() && s2 == s1.substr(0, i))
                return false;
                
        }
        
        return true;
    }
};