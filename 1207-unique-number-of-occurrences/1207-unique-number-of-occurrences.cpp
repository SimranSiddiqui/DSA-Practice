class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        int n = arr.size();
        
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        
        unordered_map<int, int> occur;
        for(auto it : mp)
        {
            if(occur.find(it.second) != occur.end())
                return false;
            occur[it.second]++;
        }
        
        return true;
        
    }
};