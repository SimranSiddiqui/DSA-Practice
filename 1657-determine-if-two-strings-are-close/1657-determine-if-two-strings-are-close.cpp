class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int mp1[26]={0},mp2[26]={0};
        
        int n1=word1.size(),n2=word2.size();
        
        for (char c : word1) mp1[c-'a']++;
        for (char c : word2) mp2[c-'a']++;
        
        for(int i=0;i<n1;i++) if(!mp2[word1[i]-'a']) return false;
        sort(mp1,mp1+26);
        sort(mp2,mp2+26);
        for (int i=0;i<26;i++) {
            if (mp1[i]!=mp2[i]) return false;
        }
        return true;
    }
};