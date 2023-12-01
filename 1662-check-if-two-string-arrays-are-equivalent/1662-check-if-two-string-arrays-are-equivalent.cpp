class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string w1=" ", w2=" ";
        int n1 = word1.size();
        int n2 = word2.size();
        for(int i=0;i<n1;i++)
        {
            w1 += word1[i];
        }
        for(int i=0;i<n2;i++)
        {
            w2 += word2[i];
        }
        
        return w1 == w2;
    }
};