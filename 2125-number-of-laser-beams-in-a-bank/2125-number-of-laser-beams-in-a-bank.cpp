class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].length();
        
        vector<int> counts;
        
        for(int i=0;i<n;i++)
        {
            int count = 0;
            for(int j=0;j<m;j++)
            {
                if(bank[i][j] == '1')
                    count++;
            }
            
            if(count)
            counts.push_back(count);
        }
        
        int ans =0;
        for(int i=1;i<counts.size();i++)
        {
            ans += counts[i] * counts[i-1];
        }
        
        return ans;
    }
};