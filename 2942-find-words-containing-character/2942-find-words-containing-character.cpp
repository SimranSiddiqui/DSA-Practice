class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            for(auto it : words[i])
            {
                if(it == x)
                {
                    ans.push_back(i);
                    break;
                }
            }
        }
        
        return ans;
    }
};