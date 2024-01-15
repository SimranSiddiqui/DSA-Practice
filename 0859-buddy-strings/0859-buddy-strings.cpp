class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        bool same = false, once = false;
        
        if(n != m)
            return 0;
        
        map<pair<char, char>, int> mp;
        for(int i=0;i<n;i++)
        {
            mp[make_pair(s[i], goal[i])]++;
        }
        
        for(auto it: mp)
        {
            pair<char, char> x = it.first;
            //cout << x.first << " " << x.second;
            if(x.first == x.second && it.second > 1)
            {
                same = true;
            }
            else if(x.first != x.second)
            {
                if(it.second > 1 || once)
                    return 0;
                else if(mp.find({x.second, x.first}) == mp.end())
                    return 0;
                else if(mp[{x.second, x.first}] > 1)
                    return 0;
                else
                    mp.erase({x.second, x.first});
                
                once = true;
            }
        }
        
       // cout << "yeah";
        return once || same;
    }
};