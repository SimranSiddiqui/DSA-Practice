class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int currMin = prices[0];
        int profit = INT_MIN;
        
        for(int i=1;i<n;i++)
        {
            if(prices[i] > currMin)
            {
                profit = max(profit, prices[i] - currMin);
            }
            
            currMin = min(currMin, prices[i]);
        }
        
        if(profit == INT_MIN)
            return 0;
        return profit;
    }
};