class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int n = items.size();
        unordered_map<string,int> mp;
        
        mp["type"] = 0;
        mp["color"]= 1;
        mp["name"] = 2;
        
        int ans =0;
        
        for(int i=0;i<n;i++)
        {
            if(items[i][mp[ruleKey]] == ruleValue)
                ans++;
        }
        
        return ans;
    }
};