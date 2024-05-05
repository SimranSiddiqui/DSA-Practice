class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.length();
        unordered_map<string, int> mp;
        
        for(int i=0;i<n;i+=k)
        {
            mp[word.substr(i, k)]++;
        }
        
        int maxi = INT_MIN;
        for(auto it: mp){
            maxi = max(maxi, it.second);
        }
        
        return n/k - maxi;
    }
};