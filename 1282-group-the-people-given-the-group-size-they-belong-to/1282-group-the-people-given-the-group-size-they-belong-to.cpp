class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        unordered_map<int, vector<int>> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[groupSizes[i]].push_back(i);
        }
        
        vector<vector<int>> ans;
        
        for(auto it : mp)
        {
            int size = it.first;
            for(int i=0;i<it.second.size();)
            {
                int j =0;
                vector<int> x;
                while(i<it.second.size() && j < size)
                {
                    x.push_back(it.second[i]);
                    i++;
                    j++;
                }
                
                ans.push_back(x);
            }
        }
        
        return ans;
    }
};