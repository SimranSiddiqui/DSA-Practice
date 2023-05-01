class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> mp;
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                pair<int, int> x = make_pair(i, j);
                mp[mat[i][j]] = x;
            }
        }
        
        vector<int> row(n, 0), column(m, 0);
        for(int i=0;i<m*n;i++)
        {
            row[mp[arr[i]].first]++;
            column[mp[arr[i]].second]++;
            
            if(row[mp[arr[i]].first] == m)
                return i;
            if(column[mp[arr[i]].second] == n)
                return i;
        }
        
        return -1;
    }
};