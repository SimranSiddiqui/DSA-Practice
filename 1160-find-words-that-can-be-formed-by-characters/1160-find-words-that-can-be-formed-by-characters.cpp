class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> mp;
        int charLen = chars.length();
        int wordLen = words.size();
        
        for(int i=0;i<charLen;i++)
        {
            mp[chars[i]]++;
        }
        
         int ans = 0;
        for(int i=0;i<wordLen;i++)
        {
            unordered_map<char,int> temp;
            for(int j=0;j<words[i].length();j++)
            {
                temp[words[i][j]]++;
            }
            
            int j;
            for(j=0;j<words[i].length();j++)
            {
               if( mp.find(words[i][j])==mp.end()  || temp[words[i][j]] > mp[words[i][j]]) 
               {
                   break;
               }
            }
            
            if(j==words[i].length())
               ans += words[i].length();  
        }
        
        return ans;
    }
};