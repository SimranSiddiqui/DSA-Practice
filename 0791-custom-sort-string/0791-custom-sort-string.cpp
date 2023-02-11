   string x;

class Solution {
    
    static bool comp(char a, char b)
    {
        return x.find(a) < x.find(b); 
    }
    
public:
    string customSortString(string order, string s) { 
        x = order;
        sort(s.begin(), s.end(), comp);
        
        return s;
    }
};