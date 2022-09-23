class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> mp;
        int count  =0;
        int n = s.length();
        
        for(int i=0;i<n;i++)
        {
            if(target.find(s[i]) != -1)
            mp[s[i]]++;
        }
       
        while(mp.size()!=0)
        {
            int i=0;
            while(i<target.size())
            {
                if(mp[target[i]] >0)
                {
                    mp[target[i]]--;
                }
                else
                    break;
                i++;
            }
            
            if(i<target.size())
                break;
            else
                count++;
                    
        }
        
        return count;
            
    }
};