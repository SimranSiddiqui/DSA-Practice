class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> mp;
        int n = heights.size();
        
        for(int i=0;i<n;i++)
        {
            mp[heights[i]] = names[i];
        }
        
        sort(heights.begin(), heights.end(), greater<int>());
        
        for(int i=0;i<n;i++)
        {
            names[i] = mp[heights[i]];
        }
        
        return names;
    }
};