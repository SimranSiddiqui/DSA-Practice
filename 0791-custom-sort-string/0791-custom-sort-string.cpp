    unordered_map<char, int> mp;
class Solution {
    static bool comp(char a, char b)
    {
        return mp[a] < mp[b]; 
    }
    
public:
    string customSortString(string order, string s) { 
        for(int i=0;i<order.length();i++)
        {
           mp[order[i]] = i;
        }
        sort(s.begin(), s.end(), comp);
        
        return s;
    }
};