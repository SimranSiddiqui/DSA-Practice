class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mp;
        vector<int> a, b;
        vector<vector<int>> ans;
        
        for(auto it: matches)
        {
            mp[it[1]]++;
        }
        
        for(auto it: matches)
        {
            if(mp[it[1]] == 1 ){
                a.push_back(it[1]);
                mp[it[1]]++;
            }
            if(mp.find(it[0]) == mp.end()){
                b.push_back(it[0]);
                mp[it[0]] = 2;
            }
        }
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        ans.push_back(b);
        ans.push_back(a);
        
        return ans;
    }
};