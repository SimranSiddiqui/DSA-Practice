class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        int n = strs.size();
        
        for(int i=0;i<n;i++)
        {
            string s = strs[i]; 
            sort(strs[i].begin(),strs[i].end());
            if(mp.find(strs[i]) == mp.end())
            {
                mp[strs[i]]  = {s};
            }
            else
            {
                mp[strs[i]].push_back(s);
            }
        }
        
        vector<vector<string>> ans;
        for(auto it: mp)
        {
           ans.push_back(it.second); 
        }
        
        return ans;
    }
};