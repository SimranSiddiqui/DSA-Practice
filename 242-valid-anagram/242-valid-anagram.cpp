class Solution {
public:
    bool isAnagram(string s, string t) {
        int size1 = s.length();
        int size2 = t.length();
        if(size1 != size2)
            return false;
        
       map<char,int> map;
        for(int i=0;i<size1;i++)
        {
            map[s[i]]++;
        }
        for(int i=0;i<size2;i++)
        {
            if(map.find(t[i])==map.end())     // return end() if the key is not found in the 
                                                 // map
                return false;
            else
                map[t[i]]--;
        }
        
        for(auto it:map)
        {
            if(it.second)
            return false;
        }
        return true;
        
        
    }
};