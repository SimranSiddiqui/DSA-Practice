class Solution {
public:
    bool isPathCrossing(string path) {
        int i = 0, j=0;
        map<pair<int,int>, int> mp; 
        mp[{0,0}]++;
        
        for(auto it: path)
        {
            if(it == 'N')
                j++;
            else if(it == 'S')
                j--;
            else if(it == 'E')
                i++;
            if(it == 'W')
                i--;
            
            if(mp.find({i,j}) != mp.end())
                return true;
            mp[{i, j}]++;
        }
        
        return false;
    }
};