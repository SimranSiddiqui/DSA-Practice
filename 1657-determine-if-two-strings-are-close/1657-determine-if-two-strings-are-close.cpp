class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        if(n!=m)
            return 0;
        
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        
        for(int i=0;i<n;i++)
        {
            freq1[word1[i] - 'a']++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(freq1[word2[i] - 'a'] == 0)
                return 0;
            
            freq2[word2[i] - 'a']++;
        }
        
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        
        for(int i=0;i<26;i++)
        {
            if(freq1[i] != freq2[i])
                return 0;
        }
        
        return 1;
    }
};