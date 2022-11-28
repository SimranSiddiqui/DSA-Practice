class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> win;
        unordered_map<int,int> lose;
        int n = matches.size();
        
        for(int i=0;i<n;i++)
        {
            win[matches[i][0]]++;
            lose[matches[i][1]]++;
        }
        
        vector<int> no;
        vector<int> one;
        for(auto it : win)
        {
            if(lose.find(it.first) == lose.end())
            {
                no.push_back(it.first);
            }
        }
        
        for(auto it: lose)
        {
            if(it.second == 1)
                one.push_back(it.first);
        }
        
        sort(no.begin(), no.end());
        sort(one.begin(), one.end());
        
        vector<vector<int>> ans = {no, one};
        
        return ans;
    }
};