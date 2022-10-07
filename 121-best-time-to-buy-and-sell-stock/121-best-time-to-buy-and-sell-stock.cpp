class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int minLeft = prices[0];
        int maxProfit = INT_MIN;
        for(int i=1;i<n;i++)
        {
            maxProfit = max(maxProfit, prices[i]-minLeft);
            minLeft = min(minLeft, prices[i]);
        }
        
        if(maxProfit > 0)
        return maxProfit;
        else
            return 0;
    }
};