class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> freq;
        int count=1;
        for(int i=0;i<s.length();i++){
            if(freq.find(s[i])!=freq.end())
            {
                freq.clear();
                count++;
            }
            
            freq.insert(s[i]);
        }
        return count;
    }
};