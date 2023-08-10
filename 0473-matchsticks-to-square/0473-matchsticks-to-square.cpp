class Solution {
    bool solve(int n, vector<int> &match, vector<int> &side)
    {
        if(n < 0)
        {
            return side[0] == side[1] && side[1] == side[2] && side[2] == side[3];
        }
        
        for(int i=0;i<4;i++)
        {
            if(side[i]-match[n] < 0) continue;
            
                side[i] -= match[n];
                if(solve(n-1, match, side)) return true;
                side[i] += match[n];
        }
        
        return false;
    }
    
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum%4)
            return 0;
        
        sort(matchsticks.begin(), matchsticks.end());
        int len = sum/4;
        vector<int> side(4, len);
        return solve(n-1, matchsticks, side);
    }
};