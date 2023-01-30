class Solution {
public:
    bool digitCount(string num) {
        unordered_map<char, int> mp;
        int n = num.length();
        
        for(int i=0;i<n;i++)
        {
            mp[num[i]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(mp[i + '0'] != num[i]-'0')
             return false;   
        }
        
        return true;
    }
};