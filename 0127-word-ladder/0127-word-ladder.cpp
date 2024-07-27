class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> mp;
        
        for(auto str: wordList)
        {
            mp[str]++;
        }
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        if(mp.find(beginWord) != mp.end())
            mp.erase(beginWord);
        
        while(!q.empty())
        {
            string curr = q.front().first;
            int len = q.front().second;
            q.pop();
            
            if(curr == endWord) return len;
            
            for(int i=0;i<curr.length();i++)
            {
                string word = curr;
                for(char c = 'a';c <= 'z' ; c++)
                {
                    word[i] = c;
                    
                    if(mp.find(word) != mp.end())
                    {
                        q.push({word, len+1});
                        mp.erase(word);
                    }
                }
            }
        }
        
        return 0;
    }
};